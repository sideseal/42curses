/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/02 03:15:09 by gychoi           ###   ########.fr       */
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

void	PmergeMe::fordJohnsonSort(std::vector<int>& v, int size)
{
	std::cout << "vec: "; showVector(v); std::cout << "size: " << size << std::endl;
	if (size <= 1)
	{
		return;
	}

	int		staggler = 0;
	bool	hasStaggler = false;

	if (size % 2)
	{
		staggler = v[size - 1];
		hasStaggler = true;
		v.erase(v.begin() + size - 1);
		size--;
	}

	for (int i = 0; i < size; i += 2)
	{
		if (v[i] < v[i + 1])
		{
			std::swap(v[i], v[i + 1]);

			for (size_t j = size; j < v.size(); j *= 2)
			{
				std::swap(v[j + i], v[j + i + 1]);
				j *= 2; // 여기부터 다시
			}
		}
	}

	std::cout << "swap: "; showVector(v); std::cout << std::endl;

	std::vector<int>	main(size / 2);
	std::vector<int>	pend(size / 2);
	std::vector<int>	temp;
	size_t				tIdx;

	for (int i = 0; i < size / 2; i++)
	{
		main[i] = v[2 * i];

		for (size_t j = size; j < v.size(); j *= j)
		{
			temp.push_back(v[j + (2 * i)]);
		}
	}
	for (int i = 0; i < size / 2; i++)
	{
		pend[i] = v[2 * i + 1];

		for (size_t j = size; j < v.size(); j *= j)
		{
			temp.push_back(v[j + (2 * i + 1)]);
			tIdx = j;
		}
	}
	if (hasStaggler)
	{
		std::cout << "staggler: " << staggler << std::endl;
		pend.push_back(staggler);
	}
	for (size_t i = tIdx + size; i < v.size(); i++)
	{
		temp.push_back(v[i]);
	}
	std::cout << "main: "; showVector(main); std::cout << std::endl;
	std::cout << "pend: "; showVector(pend); std::cout << std::endl;
	std::cout << "temp: "; showVector(temp); std::cout << std::endl;

	main.insert(main.end(), pend.begin(), pend.end());
	main.insert(main.end(), temp.begin(), temp.end());



	v = main;

	fordJohnsonSort(v, size / 2);



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

