/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/02 21:40:22 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const& fixed);
		Fixed&	operator=(Fixed const& fixed);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif	// FIXED_HPP
