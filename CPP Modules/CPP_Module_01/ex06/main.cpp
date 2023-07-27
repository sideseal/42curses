/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:10:24 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/28 02:33:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char* argv[])
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
	std::string	level(argv[1]);
	harl.complain(level);
	return (0);
}
