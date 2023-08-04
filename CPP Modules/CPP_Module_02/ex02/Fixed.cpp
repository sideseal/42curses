/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:46:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 17:50:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(Fixed const& fixed)
{
	_rawBits = fixed.getRawBits();
}

Fixed::Fixed(int const intValue)
{
	_rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue)
{
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed&	Fixed::operator=(Fixed const& fixed)
{
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void) {}

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

bool	Fixed::operator>(Fixed const& fixed) const
{
	return (_rawBits > fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const& fixed) const
{
	return (_rawBits < fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const& fixed) const
{
	return (_rawBits >= fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const& fixed) const
{
	return (_rawBits <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const& fixed) const
{
	return (_rawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const& fixed) const
{
	return (_rawBits != fixed.getRawBits());
}

typedef long long	int64;

Fixed	Fixed::operator+(Fixed const& fixed) const
{
	Fixed	ret;
	int64	b1 = _rawBits;
	int64	b2 = fixed.getRawBits();

	ret.setRawBits(static_cast<int>(b1 + b2));
	return (ret);
}

Fixed	Fixed::operator-(Fixed const& fixed) const
{
	Fixed	ret;
	int64	b1 = _rawBits;
	int64	b2 = fixed.getRawBits();

	ret.setRawBits(static_cast<int>(b1 - b2));
	return (ret);
}

Fixed	Fixed::operator*(Fixed const& fixed) const
{
	Fixed	ret;
	int64	b1 = _rawBits;
	int64	b2 = fixed.getRawBits();

	ret.setRawBits(static_cast<int>((b1 * b2) / (1 << _fractionalBits)));
	return (ret);
}

Fixed	Fixed::operator/(Fixed const& fixed) const
{
	Fixed	ret;
	int64	b1 = _rawBits;
	int64	b2 = fixed.getRawBits();

	ret.setRawBits(static_cast<int>((b1 * (1 << _fractionalBits) / b2)));
	return (ret);
}

Fixed&	Fixed::operator++(void)
{
	++_rawBits;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--_rawBits;
	return (*this);
}

Fixed const	Fixed::operator++(int)
{
	Fixed	temp(*this);

	_rawBits++;
	return (temp);
}

Fixed const	Fixed::operator--(int)
{
	Fixed	temp(*this);

	_rawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	return ((a > b) ? a : b);
}
