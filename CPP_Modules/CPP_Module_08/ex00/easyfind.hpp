/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:52:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/30 20:59:46 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <stdexcept>
#include <sstream>

template <typename T>
typename T::iterator	easyfind(T& container, int const& value)
{
	typename T::iterator	it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
		{
			return it;
		}
	}

	std::ostringstream	msg;
	msg << "Value " << value << " not found in container";
	throw std::runtime_error(msg.str());
}

template <typename T>
typename T::const_iterator	easyfind(T const& container, int const& value)
{
	typename T::const_iterator	cit;
	for (cit = container.begin(); cit != container.end(); cit++)
	{
		if (*cit == value)
		{
			return cit;
		}
	}

	std::ostringstream	msg;
	msg << "Value " << value << " not found in container";
	throw std::runtime_error(msg.str());
}

#endif /* __EASYFIND_HPP__ */
