/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:51:34 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/22 17:12:10 by gychoi           ###   ########.fr       */
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

// for volatile type swap
template <typename T>
void	swap(T volatile& a, T volatile& b)
{
	T volatile	temp = a;

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

// for constant type comparision
template <typename T>
T const&	min(T const& a, T const& b)
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

// for constant type comparision
template <typename T>
T const&	max(T const& a, T const& b)
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

// for volatile type comparision
template <typename T>
T volatile&	min(T volatile& a, T volatile& b)
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

// for volatile type comparision
template <typename T>
T volatile&	max(T volatile& a, T volatile& b)
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

// for const volatile type comparision
template <typename T>
T const volatile&	min(T const volatile& a, T const volatile& b)
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

// for const volatile type comparision
template <typename T>
T const volatile&	max(T const volatile& a, T const volatile& b)
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
