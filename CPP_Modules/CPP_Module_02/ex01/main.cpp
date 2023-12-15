/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 01:45:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Fixed.hpp"

static void	_printFixedNumber(Fixed const& fixed)
{
	std::cout << "Argument is " << fixed << std::endl;
	std::cout << "Argument is " << fixed.toInt() << " as integer" << std::endl;
	std::cout << "Argument is " << fixed.toFloat() << " as float" << std::endl;
}

static int	_testFixedNumber(char* arg)
{
	char*	end;
	int		intValue = std::strtol(arg, &end, 10);
	
	if (*end == '\0')
	{
		Fixed	intFixed(intValue);
		_printFixedNumber(intFixed);
	}
	else
	{
		float	floatValue = std::strtof(arg, &end);
		if (*end == '\0')
		{
			Fixed	floatFixed(floatValue);
			_printFixedNumber(floatFixed);
		}
		else
		{
			std::cout << "Invalid input: " << arg << std::endl;
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	if (argc == 2)
		return _testFixedNumber(argv[1]);
	else if (argc > 2)
	{
		std::cout << "Usage: " << argv[0] << " <number>" << std::endl;
		return 1;
	}
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
