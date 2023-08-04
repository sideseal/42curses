/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:21:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 18:37:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	_sign(Point const p1, Point const p2, Point const p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1, d2, d3;
	bool	onEdge, hasNeg, hasPos;

	d1 = _sign(point, a, b);
	d2 = _sign(point, b, c);
	d3 = _sign(point, c, a);
	onEdge = false;
	if (d1 == 0 || d2 == 0 || d3 == 0)
		onEdge = true;
	hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	if (onEdge || (hasNeg && hasPos))
		return false;
	return (true);
}
