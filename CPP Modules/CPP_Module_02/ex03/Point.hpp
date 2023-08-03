/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:20:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 01:39:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& point);
		Point&	operator=(Point const& point);
		~Point(void);

		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif	// POINT_HPP
