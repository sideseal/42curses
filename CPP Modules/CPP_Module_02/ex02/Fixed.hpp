/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/04 01:43:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const& fixed);
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed&	operator=(Fixed const& fixed);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(Fixed const& fixed) const;
		bool	operator<(Fixed const& fixed) const;
		bool	operator>=(Fixed const& fixed) const;
		bool	operator<=(Fixed const& fixed) const;
		bool	operator==(Fixed const& fixed) const;
		bool	operator!=(Fixed const& fixed) const;

		Fixed	operator+(Fixed const& fixed) const;
		Fixed	operator-(Fixed const& fixed) const;
		Fixed	operator*(Fixed const& fixed) const;
		Fixed	operator/(Fixed const& fixed) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);
};

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed);

#endif	// FIXED_HPP
