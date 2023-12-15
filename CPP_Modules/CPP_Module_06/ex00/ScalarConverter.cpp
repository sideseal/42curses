/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:12:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/16 01:15:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	// 먼저 strtol 로 정수 체크하고
	// 실패하면 strtod로 실수 체크
	// 마지막으로 캐릭터 체크?
}
