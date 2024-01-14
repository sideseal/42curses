/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:42 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/14 21:47:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <algorithm>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <iostream>

class BitcoinExchange
{
private:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& other);
	BitcoinExchange&	operator=(BitcoinExchange const& other);
	~BitcoinExchange();

public:
	static void	setExchangeMap(char const* path);
	static void	execute(char const* path);

private:
	static std::map<std::time_t, double>	sDataMap;
};

#endif /* __BITCOIN_EXCHANGE_HPP__ */
