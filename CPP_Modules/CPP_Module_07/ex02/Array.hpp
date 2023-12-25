/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:01:24 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/25 21:51:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <cstring>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const& target);
	Array&				operator=(Array const& target);
	~Array();

public:
	unsigned int const&	size() const;
	T&					operator[](unsigned int n);
	T const&			operator[](unsigned int n) const;

private:
	unsigned int	mSize;
	T*				mData;
};

template <typename T>
std::ostream&	operator<<(std::ostream& os, Array<T> const& arr);

#include "Array.tpp"
#endif /* __ARRAY_HPP__ */
