/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/03 22:11:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::sSequence;

static int	_getValidElement(char const* str);

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
		for (int i = 0; i < turn; i++)
		{
			staggler.push_back(v[(i + 1) * (size - 1)]);
			v.erase(v.begin() + ((i + 1) * (size - 1)));
		}
		size--;
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



}

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

// 소수점도 Invalid한 요소로 처리해야 한다.
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

