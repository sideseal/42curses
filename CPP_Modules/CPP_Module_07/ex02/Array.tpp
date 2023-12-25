/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:01:24 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/25 19:32:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : mSize(0)
{
	this->mData = new T[this->mSize];
}

template <typename T>
Array<T>::Array(unsigned int n) : mData(0) // for throw-destruction safety
{
	if (static_cast<int>(n) < 0)
	{
		throw std::out_of_range("Invalid index");
	}
	else
	{
		this->mSize = n;
		this->mData = new T[this->mSize]();
	}
}

template <typename T>
Array<T>::Array(Array const& target) : mSize(target.mSize)
{
	this->mData = new T[this->mSize]();
	for (unsigned int i = 0; i < this->mSize; i++)
	{
		this->mData[i] = target.mData[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const& target)
{
	if (this != &target)
	{
		delete[] mData;
		this->mSize = target.mSize;
		this->mData = new T[this->mSize]();
		for (unsigned int i = 0; i < this->mSize; i++)
		{
			this->mData[i] = target.mData[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] mData;
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

template <typename T>
unsigned int const&	Array<T>::size() const
{
	return this->mSize;
}

template <typename T>
T&	Array<T>::operator[](unsigned int n)
{
	if (static_cast<int>(n) < 0)
	{
		throw std::out_of_range("Invalid index");
	}
	else if (n >= this->mSize)
	{
		throw std::out_of_range("Index is out of range");
	}
	else
	{
		// valid index
	}
	return this->mData[n];
}

template <typename T>
T const&	Array<T>::operator[](unsigned int n) const
{
	std::cout << "#################I AM IN CONST#################" << std::endl;
	if (static_cast<int>(n) < 0)
	{
		throw std::out_of_range("Invalid index");
	}
	else if (n >= this->mSize)
	{
		throw std::out_of_range("Index is out of range");
	}
	else
	{
		// valid index
	}
	return this->mData[n];
}

/* ************************************************************************** */
/*                           Global Member Function                           */
/* ************************************************************************** */

template <typename T>
std::ostream&	operator<<(std::ostream& os, Array<T> const& arr)
{
	os << &arr;
	return os;
}


#endif /* __ARRAY_TPP__ */
