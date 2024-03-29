/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:46:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 17:19:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = fixed.getRawBits();
}

Fixed::Fixed(int const intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed&	Fixed::operator=(Fixed const& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (_rawBits / (1 <<_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}
