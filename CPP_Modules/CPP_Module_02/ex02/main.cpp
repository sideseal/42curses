/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 17:56:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Fixed.hpp"

static void	_testArithmetic(void)
{
	Fixed	c(42.4242f);
	Fixed	d(42);

	std::cout << "c: " << c << "(42.4242f)" << ", d: " << d << "(42)" << std::endl;
	std::cout << "c > d : " << (c > d) << std::endl;
	std::cout << "c < d : " << (c < d) << std::endl;
	std::cout << "c >= d : " << (c >= d) << std::endl;
	std::cout << "c <= d : " << (c <= d) << std::endl;
	std::cout << "c == d : " << (c == d) << std::endl;
	std::cout << "c != d : " << (c != d) << '\n' << std::endl;

	Fixed	e(c + d);
	std::cout << "e = c + d : " << e << std::endl;
	Fixed	f(c - d);
	std::cout << "f = c - d : " << f << std::endl;
	Fixed	g(c * d);
	std::cout << "g = c * d : " << g << std::endl;
	Fixed	h(c / d);
	std::cout << "h = c / d : " << h << '\n' << std::endl;

	std::cout << "min(e, f) : " << Fixed::min(e, f) << std::endl;
	std::cout << "max(g, h) : " << Fixed::max(g, h) << '\n' << std::endl;

	Fixed const	i(-42);
	Fixed const j(-42.4242f);

	std::cout << "const i: " << i << "(-42)" << std::endl;
	std::cout << "const j: " << j << "(-42.4242f)" << std::endl;
	std::cout << "i + j : " << i + j << std::endl;
	std::cout << "i - j : " << i - j << std::endl;
	std::cout << "i * j : " << i * j << std::endl;
	std::cout << "i / j : " << i / j << '\n' << std::endl;
	std::cout << "min(i, j) : " << Fixed::min(i, j) << std::endl;
	std::cout << "max(i, j) : " << Fixed::max(i, j) << '\n' << std::endl;

	Fixed k(42424);
	Fixed l(42.4242f);

	std::cout << "k: " << k << "(42424)" << ", l: " << l << "(42.4242f)" << std::endl;
	std::cout << "k * l : " << k * l << std::endl;
	std::cout << "k / l : " << k / l << std::endl;

	Fixed tmp(k * l);
	std::cout << "tmp(k * l) : " << tmp << std::endl;
	std::cout << "tmp / l : " << tmp / l << '\n' << std::endl;

	Fixed m(42);
	Fixed n(0);
	std::cout << "m: " << m << "(42)" << ", n: " << n << "(0)" << std::endl;
	std::cout << "m * n : " << m * n << std::endl;
	std::cout << "m / n : Be aware of Division by zero" << std::endl;
//	std::cout << "m / n : " << m / n << std::endl;
	std::cout << "++m : " << ++m << std::endl;
	std::cout << "++(++m) : " << ++(++m) << std::endl;
	std::cout << "m++, m : " << m++ << ", " << m << std::endl;
	std::cout << "(m++)++ : You can not duplicate post-increment/post-decrement" << std::endl;
//	std::cout << (m++)++ << std::endl;
}

static bool	_testFixedNumber(int argc, char* argv[])
{
	if (argc > 2)
	{
		std::cout << "Usage: " << argv[0] << " test" << std::endl;
		return (false);
	}

	std::string	input = argv[1];

	if (input == "test")
		_testArithmetic();
	else
	{
		std::cout << "Invalid Option: you can use only 'test' option, sorry." << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char* argv[])
{
	if (argc >= 2)
		return (_testFixedNumber(argc, argv));

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed ( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
