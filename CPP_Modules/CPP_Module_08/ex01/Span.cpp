/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:12:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/26 01:13:41 by gychoi           ###   ########.fr       */
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
		throw out_of_range("Invalid index");
	}
	else
	{
		this->mSize = n;
	}
}

Span::Span(Span const& target) : mSize(target.mSize)
{
	for (size_t i = 0; i < this->mSize; i++)
	{
		this->mVec.push_back(target.mVec[i]);
	}
}

Span&	Span::opeartor=(Span const& target)
{
	if (this != &target)
	{
		this->mSize = target.mSize;
		std::vector<int>().swap(this->mVec);
		for (size_t i = 0; i < this->mSize; i++)
		{
			this->mVec.push_back(target.mVec[i]);
		}
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
