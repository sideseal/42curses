/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:12:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/20 21:50:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool		_isnan(double x) { return x != x; }
static bool		_isnan(float x) { return x != x; }

static double	_getValidValue(std::string const& literal);
static void		_printChar(double const& value);
static void		_printInt(double const& value);
static void		_printFloat(double const& value);
static void		_printDouble(double const& value);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

ScalarConverter::ScalarConverter()
{
	// nothing to do
}

ScalarConverter::ScalarConverter
(__attribute__((unused)) ScalarConverter const& target)
{
	// nothing to do
}

ScalarConverter&	ScalarConverter::operator=
(__attribute__((unused)) ScalarConverter const& target)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Static Member Function                           */
/* ************************************************************************** */

void	ScalarConverter::convert(std::string const& literal)
{
	try
	{
		double	value = _getValidValue(literal);

		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.precision(1);

		_printChar(value);
		_printInt(value);
		_printFloat(value);
		_printDouble(value);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Fatal Error" << std::endl;
	}
}

/* ************************************************************************** */
/*                              Static Functions                              */
/* ************************************************************************** */

static double	_getValidValue(std::string const& literal)
{
	char*	endPtr = 0;
	double	value = std::strtod(literal.c_str(), &endPtr);

	if (endPtr && *endPtr != '\0') // non-digit char founds
	{
		if (!value && literal.length() == 1)
		{
			// allow one char literal
			value = static_cast<double>(literal[0]);
		}
		else if (std::strcmp(endPtr, "f"))
		{
			// if non-digit char includes, only 'f' format allows
			throw std::invalid_argument("Invalid argument: " + literal);
		}
		else if (literal.find('.') == std::string::npos)
		{
			// '42f' - invalid literal format
			throw std::invalid_argument("Invalid argument: " + literal);
		}
		else
		{
			// valid literal format (a, 4.2f, 4.f)
		}
	}
	else
	{
		// Valid integer / float / double literal format
	}
	return value;
}

static void	_printChar(double const& value)
{
	if (_isnan(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (value < std::numeric_limits<unsigned char>::min()
		|| !!std::isprint(static_cast<unsigned char>(value)) == false)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

static void	_printInt(double const& value)
{
	if (_isnan(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void	_printFloat(double const& value)
{
	float	floatVal = static_cast<float>(value);

	if (_isnan(floatVal))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else if ((value < -std::numeric_limits<float>::max()
			  && value != -std::numeric_limits<float>::infinity())
			|| (value > std::numeric_limits<float>::max()
				&& value != std::numeric_limits<float>::infinity()))
	{
		std::cout << "float: impossible" << std::endl;
	}
	else if (floatVal == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: +inff" << std::endl;
	}
	else if (floatVal == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: -inff" << std::endl;
	}
	else
	{
		std::cout << "float: " << floatVal << "f" << std::endl;
	}
}

static void	_printDouble(double const& value)
{
	if (_isnan(value))
	{
		std::cout << "double: nan" << std::endl;
	}
	else if ((value < -std::numeric_limits<double>::max()
			  && value != -std::numeric_limits<double>::infinity())
			|| (value > std::numeric_limits<double>::max()
				&& value != std::numeric_limits<double>::infinity()))
	{
		std::cout << "double: impossible" << std::endl;
	}
	else if (value == std::numeric_limits<double>::infinity())
	{
		std::cout << "double: +inf" << std::endl;
	}
	else if (value == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "double: " << value << std::endl;
	}
}
