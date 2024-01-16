/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/14 21:01:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>		PmergeMe::sSequence;
std::deque<int>			PmergeMe::sPartialJacobsthalSequence;

static int				_getValidElement(char const* str);
static std::deque<int>	_generatePartialJacobsthalSequence();
static int				_binarySearch(int* const& arr,
									  int left, int right, int target);

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

	std::vector<ValuePair>	main;
	std::vector<ValuePair>	pend;

	for (int i = 0; i < size / 2; i++)
	{
		ValuePair	mainPair;
		ValuePair	pendPair;

		mainPair.value = v[i];
		mainPair.index = i;
		pendPair.value = v[i + size / 2];
		pendPair.index = i + size / 2;

		main.push_back(mainPair);
		pend.push_back(pendPair);
	}

	if (hasStaggler)
	{
		ValuePair	stagPair;

		stagPair.value = v[size - 1];
		stagPair.index = size - 1;

		pend.push_back(stagPair);
	}

	size_t subSequenceLen = 2;

	for (size_t i = 0; i < sPartialJacobsthalSequence.size(); i++)
	{
		if (i == 0)
		{
			main.insert(main.begin(), pend.front());
			continue;
		}

		int	pendArrSize = pend.size();
		int	currJacobNum = sPartialJacobsthalSequence[i];
		int	prevJacobNum = sPartialJacobsthalSequence[i - 1];
		int	rangeIndex = currJacobNum > pendArrSize
						 ? pendArrSize - 1
						 : currJacobNum - 1;

		subSequenceLen *= 2;
		for (int j = rangeIndex; j >= prevJacobNum; j--)
		{
			size_t	mainArrSize = main.size();
			int		mainArr[mainArrSize];
			int		endRange = std::min(subSequenceLen - 2, mainArrSize - 1);

			for (size_t k = 0; k < mainArrSize; k++)
			{
				mainArr[k] = main[k].value;
			}

			int	index = _binarySearch(mainArr, 0, endRange, pend[j].value);

			main.insert(main.begin() + index, pend[j]);
		}

		if (rangeIndex == pendArrSize - 1)
		{
			break;
		}
	}

	std::vector<int>	index;

	for (size_t i = 0; i < main.size(); i++)
	{
		index.push_back(main[i].index);
	}

	std::vector<int>().swap(temp);

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp.push_back(v[i * size + index[j]]);
		}
	}

	v = temp;
}

void	PmergeMe::fordJohnsonSort(std::deque<int>& d, int size, int turn)
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
			staggler.push_back(d[(i + 1) * size]);
			d.erase(d.begin() + ((i + 1) * size));
		}
		hasStaggler = true;
	}

	for (int i = 0; i < size; i += 2)
	{
		if (d[i] < d[i + 1])
		{
			std::swap(d[i], d[i + 1]);

			for (int j = 1; j < turn; j++)
			{
				std::swap(d[j * size + i], d[j * size + i + 1]);
			}
		}
	}

	std::deque<int>	temp;

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(d[(2 * j) + (i * size)]);
		}
		for (int j = 0; j < size / 2; j++)
		{
			temp.push_back(d[(2 * j + 1) + (i * size)]);
		}
	}

	d = temp;

	fordJohnsonSort(d, size / 2, turn * 2);

	if (!staggler.empty())
	{
		for (int i = turn; i >= 0; i--)
		{
			if (staggler.empty())
			{
				break;
			}
			d.insert(d.begin() + (i * size), staggler.back());
			staggler.pop_back();
		}
		size++;
	}

	std::vector<ValuePair>	main;
	std::vector<ValuePair>	pend;

	for (int i = 0; i < size / 2; i++)
	{
		ValuePair	mainPair;
		ValuePair	pendPair;

		mainPair.value = d[i];
		mainPair.index = i;
		pendPair.value = d[i + size / 2];
		pendPair.index = i + size / 2;

		main.push_back(mainPair);
		pend.push_back(pendPair);
	}

	if (hasStaggler)
	{
		ValuePair	stagPair;

		stagPair.value = d[size - 1];
		stagPair.index = size - 1;

		pend.push_back(stagPair);
	}

	size_t subSequenceLen = 2;

	for (size_t i = 0; i < sPartialJacobsthalSequence.size(); i++)
	{
		if (i == 0)
		{
			main.insert(main.begin(), pend.front());
			continue;
		}

		int	pendArrSize = pend.size();
		int	currJacobNum = sPartialJacobsthalSequence[i];
		int	prevJacobNum = sPartialJacobsthalSequence[i - 1];
		int	rangeIndex = currJacobNum > pendArrSize
						 ? pendArrSize - 1
						 : currJacobNum - 1;

		subSequenceLen *= 2;
		for (int j = rangeIndex; j >= prevJacobNum; j--)
		{
			size_t	mainArrSize = main.size();
			int		mainArr[mainArrSize];
			int		endRange = std::min(subSequenceLen - 2, mainArrSize - 1);

			for (size_t k = 0; k < mainArrSize; k++)
			{
				mainArr[k] = main[k].value;
			}

			int	index = _binarySearch(mainArr, 0, endRange, pend[j].value);

			main.insert(main.begin() + index, pend[j]);
		}

		if (rangeIndex == pendArrSize - 1)
		{
			break;
		}
	}

	std::deque<int>	index;

	for (size_t i = 0; i < main.size(); i++)
	{
		index.push_back(main[i].index);
	}

	std::deque<int>().swap(temp);

	for (int i = 0; i < turn; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp.push_back(d[i * size + index[j]]);
		}
	}

	d = temp;
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
(int* const& arr, int left, int right, int target)
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

