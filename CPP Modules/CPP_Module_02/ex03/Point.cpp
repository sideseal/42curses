/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:21:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 01:48:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y)
{
	const_cast<Fixed&>(_x) = x;
	const_cast<Fixed&>(_y) = y;
}

Point::Point(Point const& point)
{
	const_cast<Fixed&>(_x) = point._x;
	const_cast<Fixed&>(_y) = point._y;
}

Point&	Point::operator=(Point const& point)
{
	if (this != &point)
	{
		const_cast<Fixed&>(_x) = point._x;
		const_cast<Fixed&>(_y) = point._y;
	}
	return (*this);
}

Point::~Point(void) {}

Fixed const&	Point::getX(void) const
{
	return (_x);
}

Fixed const&	Point::getY(void) const
{
	return (_y);
}
