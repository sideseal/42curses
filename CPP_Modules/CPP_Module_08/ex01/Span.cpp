/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:12:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 01:11:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Span::Span() : mSize(0)
{
	// nothing to do
}

Span::Span(unsigned int n)
{
	if (static_cast<int>(n) < 0)
	{
		throw std::out_of_range("Invalid index");
	}
	else
	{
		this->mSize = n;
		this->mVec.reserve(this->mSize);
	}
}

Span::Span(Span const& target) : mSize(target.mSize)
{
	this->mVec.assign(target.mVec.begin(), target.mVec.end());
}

Span&	Span::operator=(Span const& target)
{
	if (this != &target)
	{
		this->mSize = target.mSize;
		std::vector<int>().swap(this->mVec);
		this->mVec.assign(target.mVec.begin(), target.mVec.end());
	}
	return *this;
}

Span::~Span()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

void	Span::addNumber(int number)
{
	if (this->mVec.size() >= this->mSize)
	{
		throw std::runtime_error("Can't store number because vector is full");
	}
	else
	{
		this->mVec.push_back(number);
	}
}

unsigned int	Span::shortestSpan() const
{
	if (this->mVec.size() <= 1)
	{
		throw std::runtime_error("Need to store more numbers to find span");
	}
	else
	{
		// enough elements to calculate span
	}

	std::deque<int>	span;
	int	(*abs)(int) = &std::abs;

	std::adjacent_difference(this->mVec.begin(), this->mVec.end(),
							 std::back_inserter(span));
	span.pop_front();
	std::transform(span.begin(), span.end(), span.begin(), abs);
	return (*std::min_element(span.begin(), span.end()));
}

unsigned int	Span::longestSpan() const
{
	if (this->mVec.size() <= 1)
	{
		throw std::runtime_error("Need to store more numbers to find span");
	}
	else
	{
		// enough elements to calculate span
	}

	std::deque<int>	span;
	int	(*abs)(int) = &std::abs;

	std::adjacent_difference(this->mVec.begin(), this->mVec.end(),
							 std::back_inserter(span));
	span.pop_front();
	std::transform(span.begin(), span.end(), span.begin(), abs);
	return (*std::max_element(span.begin(), span.end()));
}
