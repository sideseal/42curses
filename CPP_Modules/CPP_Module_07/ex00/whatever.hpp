/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:51:34 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/21 01:01:53 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void	swap(T& a, T& b)
{
	T	temp = a;

	a = b;
	b = temp;
}

template <typename T>
T&	min(T& a, T& b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename T>
T&	max(T& a, T& b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

#endif /* __WHATEVER_HPP__ */
