/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:50:56 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/14 22:50:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	else
	{
		// ready to execute
	}

	try
	{
		BitcoinExchange::setExchangeMap("./data.csv");
		BitcoinExchange::execute(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() <<  std::endl;
		return 1;
	}
	return 0;
}
