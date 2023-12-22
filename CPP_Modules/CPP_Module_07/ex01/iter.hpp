/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:03:17 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/22 18:05:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T, typename F>
void	iter(T* arr, size_t len, F const& func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T, typename F>
void	iter(T const* arr, size_t len, F const& func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	display(T const& a)
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);

	std::cout << a << std::endl;
}

template<typename F, typename T>
std::ostream&	operator<<(std::ostream& os, F(*p)(T))
{
	return os << reinterpret_cast<void*>(p);
}

#endif /* __ITER_HPP__ */
