/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/17 21:34:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCALAR_CONVERTER_HPP__
#define __SCALAR_CONVERTER_HPP__

#include <cstdlib>
#include <cstring>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& target);
	ScalarConverter&	operator=(ScalarConverter const& target);
	~ScalarConverter();

public:
	static void			convert(std::string const& literal);
};

#endif /* __SCALAR_CONVERTER_HPP__ */
