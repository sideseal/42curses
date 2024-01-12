/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:09 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/12 18:55:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double>	BitcoinExchange::sExchangeMap;


/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange()
{
	// nothing to do
}

BitcoinExchange::BitcoinExchange
(__attribute__((unused)) BitcoinExchange const& other)
{
	// nothing to do
}

BitcoinExchange&	BitcoinExchange::operator=
(__attribute__((unused)) BitcoinExchange const& other)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// nothig to do
}

/* ************************************************************************** */
/*                              Getter & Setter                               */
/* ************************************************************************** */

void	BitcoinExchange::setExchangeMap()
{

	//
}
