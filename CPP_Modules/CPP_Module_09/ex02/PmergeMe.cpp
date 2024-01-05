/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/05 22:56:28 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::sSequence;
std::deque<int>		PmergeMe::sPartialJacobsthalSequence;

static int				_getValidElement(char const* str);
static std::deque<int>	_generatePartialJacobsthalSequence();
static int				_binarySearch(std::vector<int> const& arr,
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
	std::cout << "vec : "; showVector(v); std::cout << "size: " << size << std::endl;
	if (size <= 1)
	{
		return;
	}

	std::vector<int>	staggler;

	if (size % 2)
	{
		size--;
		for (int i = 0; i < turn; i++)
		{
			staggler.push_back(v[(i + 1) * (size)]);
			v.erase(v.begin() + ((i + 1) * (size)));
		}
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
	std::cout << "temp: "; showVector(temp); std::cout << std::endl;

	v = temp;

	fordJohnsonSort(v, size / 2, turn * 2);
	std::cout << "=========recur=========" << std::endl;

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

	std::cout << "vec: "; showVector(v); std::cout << "size: " << size << std::endl;

	// 인덱스를 담아놓는 pair를 만들고, size 범위의 index를 담아놓고, 이후의
	// 배열들에 대해 해당 인덱스를 적용하는 방식?

}

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

// 소수점도 Invalid한 요소로 처리해야 한다.
// 0은 포함되면 안 된다.
static int	_getValidElement(char const* str)
{
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
