/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 04:00:07 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	_printPoint(std::string const name, Point const& point)
{
	std::cout << name<< "(" << point.getX() << ", " << point.getY() << ")" << std::endl;
}

int	main(void)
{
	Point	a(0, 42.42);
	Point	b(42.42, 0);
	Point	c(0, 0);
	_printPoint("a", a);
	_printPoint("b", b);
	_printPoint("c", c);
	std::cout << "----------" << std::endl;
	Point	p1(4.2, 4.2);
	_printPoint("p1", p1);
	std::cout << bsp(a, b, c, p1) << std::endl;
	Point	p2(10, 10);
	_printPoint("p2", p2);
	std::cout << bsp(a, b, c, p2) << std::endl;
	Point	p3(1000, 1000);
	_printPoint("p3", p3);
	std::cout << bsp(a, b, c, p3) << std::endl;
	Point	p4(0, 21.42);
	_printPoint("p4", p4);
	std::cout << bsp(a, b, c, p4) << std::endl;
	Point	p5(-0.01, -0.01);
	_printPoint("p5", p5);
	std::cout << bsp(a, b, c, p5) << std::endl;
	Point	p6(0.01, 42.42);
	_printPoint("p6", p6);
	std::cout << bsp(a, b, c, p6) << std::endl;
	Point	p7(42.42, 0.01);
	_printPoint("p7", p7);
	std::cout << bsp(a, b, c, p7) << std::endl;
	Point	p8(0, 42.42);
	_printPoint("p8", p8);
	std::cout << bsp(a, b, c, p8) << std::endl;
	Point	p9(42.42, 0);
	_printPoint("p9", p9);
	std::cout << bsp(a, b, c, p9) << std::endl;
	Point	p10(0, 0);
	_printPoint("p10", p10);
	std::cout << bsp(a, b, c, p10) << std::endl;
	Point	p11(-1, -1);
	_printPoint("p11", p11);
	std::cout << bsp(a, b, c, p11) << std::endl;
	Point	p12(40, 2);
	_printPoint("p12", p12);
	std::cout << bsp(a, b, c, p12) << std::endl;
	Point	p13(2, 40);
	_printPoint("p13", p13);
	std::cout << bsp(a, b, c, p13) << std::endl;
	Point	p14(14.14, 14.14);
	_printPoint("p14", p14);
	std::cout << bsp(a, b, c, p14) << std::endl;
	return 0;
}
