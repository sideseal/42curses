/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:03:17 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/21 01:22:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T, typename F>
void	iter(T* arr, size_t len, F& func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	display(T& a)
{
	std::cout << a << std::endl;
}

#endif /* __ITER_HPP__ */
