/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:12:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 01:11:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <algorithm>
#include <cmath>
#include <deque>
#include <numeric>
#include <stdexcept>
#include <vector>

class	Span
{
public:
	Span();
	Span(unsigned int n);
	Span(Span const& target);
	Span&				operator=(Span const& target);
	~Span();

public:
	void				addNumber(int number);
	template<typename I>
	void				addNumbers(I first, I last);
	unsigned int		shortestSpan() const;
	unsigned int		longestSpan() const;

private:
	unsigned int		mSize;
	std::vector<int>	mVec;
};

template<typename I>
void	Span::addNumbers(I first, I last)
{
	int	dist = std::distance(first, last);

	if (this->mVec.size() + dist > this->mSize)
	{
		throw std::runtime_error("Not enough vector space to store numbers");
	}
	else
	{
		this->mVec.insert(this->mVec.end(), first, last);
	}
}

#endif /* __SPAN_HPP__ */
