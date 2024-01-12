/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:42 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/12 19:02:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& other);
	BitcoinExchange&	operator=(BitcoinExchange const& other);
	~BitcoinExchange();

public:
	void	setExchangeMap();

private:
	static std::map<std::string, double>	sExchangeMap;
};

#endif /* __BITCOIN_EXCHANGE_HPP__ */
