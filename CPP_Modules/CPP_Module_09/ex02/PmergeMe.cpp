/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/08 00:01:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::sSequence;
std::deque<int>		PmergeMe::sPartialJacobsthalSequence;

static int				_getValidElement(char const* str);
static std::deque<int>	_generatePartialJacobsthalSequence();
static int				_binarySearch(std::vector<int> const& arr,
									  int left, int right, int target);
static int				_binarySearch(std::deque<int> const& arr,
									  int left, int right, int target);

#include <iostream>
void	showVector(std::vector<int>& v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
}

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

PmergeMe::PmergeMe()
{
	// nothing to do
}

PmergeMe::PmergeMe
(__attribute__((unused)) PmergeMe const& other)
{
	// nothing to do
}

PmergeMe&	PmergeMe::operator=
(__attribute__((unused)) PmergeMe const& other)
{
	return *this;
}

PmergeMe::~PmergeMe()
{
	// nothing to do
}

/* ************************************************************************** */
/*                              Getter & Setter                               */
/* ************************************************************************** */

std::vector<int> const&	PmergeMe::getSequence()
{
	return sSequence;
}

void	PmergeMe::setSequence(char** seq, int len)
{
	sSequence.reserve(len);

	for (int i = 1; i < len; i++)
	{
		sSequence.push_back(_getValidElement(seq[i]));
	}

	sPartialJacobsthalSequence = _generatePartialJacobsthalSequence();
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

void	PmergeMe::fordJohnsonSort(std::vector<int>& v, int size, int turn)
{
	std::cout << " vec: "; showVector(v);
	std::cout << "size: " << size << ", turn: " << turn << std::endl;

	if (size <= 1)
	{
		return;
	}

	std::vector<int>	staggler;
	bool				hasStaggler = false;

	if (size % 2)
	{
		size--;
		for (int i = 0; i < turn; i++)
		{
			std::cout << "staggler: " << v[(i + 1) * (size)] << std::endl;
			staggler.push_back(v[(i + 1) * size]);
			v.erase(v.begin() + ((i + 1) * size));
		}
		hasStaggler = true;
	}

	for (int i = 0; i < size; i += 2)
	{
		if (v[i] < v[i + 1])
		{
			std::swap(v[i], v[i + 1]);

			for (int j = 1; j < turn; j++)
			{
				std::swap(v[j * size + i], v[j * size + i + 1]);
			}
		}
	}

	std::cout << "swap: "; showVector(v); std::cout << std::endl;

	std::vector<int>	temp;

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(v[(2 * j) + (i * size)]);
		}
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(v[(2 * j + 1) + (i * size)]);
		}
	}

	std::cout << "temp: "; showVector(v); std::cout << std::endl;

	v = temp;

	std::cout << " vec: "; showVector(v); std::cout << std::endl;

	fordJohnsonSort(v, size / 2, turn * 2);

	std::cout << "==========recur==========" << std::endl;

	if (!staggler.empty())
	{
		for (int i = turn; i >= 0; i--)
		{
			if (staggler.empty())
			{
				break;
			}
			v.insert(v.begin() + (i * size), staggler.back());
			staggler.pop_back();
		}
		size++;
	}

	std::cout << " vec: "; showVector(v);
	std::cout << "size: " << size << ", turn: " << turn << std::endl;

	std::vector<int>	main;
	std::vector<int>	pend;

	for (int i = 0; i < size / 2; i++)
	{
		main.push_back(v[i]);
		pend.push_back(v[i + size / 2]);
	}

	if (hasStaggler)
	{
		pend.push_back(v[size - 1]);
	}

	std::cout << "main: "; showVector(main); std::cout << std::endl;
	std::cout << "pend: "; showVector(pend); std::cout << std::endl;

	main.insert(main.begin(), pend.front());

	for (int i = 1; i < sPartialJacobsthalSequence.size(); i++)
	{
		int		currJacobNum = sPartialJacobsthalSequence[i];
		int		prevJacobNum = sPartialJacobsthalSequence[i - 1];
		int		rangeIndex = currJacobNum > pend.size()
							 ? pend.size() - 1
							 : currJacobNum - 1;

		for (int j = rangeIndex; j >= prevJacobNum; j--)
		{
			int	index = _binarySearch(main, 0, main.size() - 1, pend[j]);

			main.insert(main.begin() + index, pend[j]);
		}

		if (rangeIndex == pend.size() - 1)
		{
			break;
		}
	}

	std::cout << "sort: "; showVector(main); std::cout << std::endl;

	std::vector<int>	index;

	for (int i = 0; i < main.size(); i++)
	{
		std::vector<int>::iterator	it = std::find(v.begin(), v.end(), main[i]);
		index.push_back(std::distance(v.begin(), it));
	}

	std::cout << " idx: "; showVector(index); std::cout << std::endl;

	std::vector<int>().swap(temp);

	// 중복 인덱스에 대한 문제 발생
	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp.push_back(v[i * size + index[j]]);
		}
	}

	std::cout << "temp: "; showVector(temp); std::cout << std::endl;

	v = temp;
}

void	PmergeMe::fordJohnsonSort(std::deque<int>& v, int size, int turn)
{
	if (size <= 1)
	{
		return;
	}

	std::deque<int>	staggler;
	bool			hasStaggler = false;

	if (size % 2)
	{
		size--;
		for (int i = 0; i < turn; i++)
		{
			staggler.push_back(v[(i + 1) * (size)]);
			v.erase(v.begin() + ((i + 1) * (size)));
		}
		hasStaggler = true;
	}

	for (int i = 0; i < size; i += 2)
	{
		if (v[i] < v[i + 1])
		{
			std::swap(v[i], v[i + 1]);

			for (int j = 1; j < turn; j++)
			{
				std::swap(v[j * size + i], v[j * size + i + 1]);
			}
		}
	}

	std::deque<int>	temp;

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(v[(2 * j) + (i * size)]);
		}
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(v[(2 * j + 1) + (i * size)]);
		}
	}

	v = temp;

	fordJohnsonSort(v, size / 2, turn * 2);

	if (!staggler.empty())
	{
		for (int i = turn; i >= 0; i--)
		{
			if (staggler.empty())
			{
				break;
			}
			v.insert(v.begin() + (i * size), staggler.back());
			staggler.pop_back();
		}
		size++;
	}

	std::deque<int>	main;
	std::deque<int>	pend;

	for (int i = 0; i < size / 2; i++)
	{
		main.push_back(v[i]);
		pend.push_back(v[i + size / 2]);
	}

	if (hasStaggler)
	{
		pend.push_back(v[size - 1]);
	}

	main.insert(main.begin(), pend.front());

	for (int i = 1; i < sPartialJacobsthalSequence.size(); i++)
	{
		int		currJacobNum = sPartialJacobsthalSequence[i];
		int		prevJacobNum = sPartialJacobsthalSequence[i - 1];
		int		rangeIndex = currJacobNum > pend.size()
							 ? pend.size() - 1
							 : currJacobNum - 1;

		for (int j = rangeIndex; j >= prevJacobNum; j--)
		{
			int	index = _binarySearch(main, 0, main.size() - 1, pend[j]);

			main.insert(main.begin() + index, pend[j]);
		}

		if (rangeIndex == pend.size() - 1)
		{
			break;
		}
	}

	std::deque<int>	index;

	for (int i = 0; i < main.size(); i++)
	{
		std::deque<int>::iterator	it = std::find(v.begin(), v.end(), main[i]);
		index.push_back(std::distance(v.begin(), it));
	}

	std::deque<int>().swap(temp);

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp.push_back(v[i * size + index[j]]);
		}
	}

	v = temp;
}

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

static int	_getValidElement(char const* str)
{
	if (str == 0 || std::strlen(str) == 0)
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else if (str[0] == '-')
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else if (str[0] == '0' && std::strlen(str) > 1)
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else
	{
		bool	signFlag = false;

		for (size_t i = 0; i < std::strlen(str); i++)
		{
			if (!std::isdigit(str[i]))
			{
				if (str[i] == '+' && signFlag == false)
				{
					signFlag = true;
					continue;
				}
				else
				{
					std::string	arg = str;
					throw std::invalid_argument("Invalid argument: " + arg);
				}
			}
		}
	}

	char*	endPtr = 0;
	double	elem = std::strtod(str, &endPtr);
	int		ret = static_cast<int>(elem);

	if (endPtr != 0 && *endPtr != '\0')
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else if (elem < 0 || elem > std::numeric_limits<int>::max())
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else if (elem == 0)
	{
		std::string	arg = str;
		throw std::invalid_argument("Invalid argument: " + arg);
	}
	else
	{
		// valid element
	}

	return ret;
}

static std::deque<int>	_generatePartialJacobsthalSequence()
{
	std::deque<int>	jacobSequence;
	size_t			n = 2;

	jacobSequence.push_back(0);
	jacobSequence.push_back(1);

	while (true)
	{
		int	jacobNum = jacobSequence[n - 1] + 2 * jacobSequence[n - 2];

		if (jacobNum < 0 || jacobNum > std::numeric_limits<int>::max())
		{
			break;
		}
		jacobSequence.push_back(jacobNum);
		n++;
	}

	jacobSequence.pop_front();
	jacobSequence.pop_front();

	return jacobSequence;
}

static int	_binarySearch
(std::vector<int> const& arr, int left, int right, int target)
{
	while (left <= right)
	{
		int	mid = left + (right - left) / 2;

		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}

static int	_binarySearch
(std::deque<int> const& arr, int left, int right, int target)
{
	while (left <= right)
	{
		int	mid = left + (right - left) / 2;

		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}

