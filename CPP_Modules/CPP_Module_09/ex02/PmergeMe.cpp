/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:50:53 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 21:39:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::sSequence;

static int	_getValidElement(char const* str);

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

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

static int	_getValidElement(char const* str)
{
	char*	endPtr = 0;
	double	elem = std::strtod(str, &endPtr);

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

	return static_cast<int>(elem);
}

