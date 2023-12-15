/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:14:21 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/28 16:44:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

typedef void (Harl::*HARL_LEVEL)(void);

void	Harl::complain(std::string level)
{
	std::string	levels[LEVEL_SIZE] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HARL_LEVEL	harlLevel[LEVEL_SIZE];

	harlLevel[DEBUG] = &Harl::debug;
	harlLevel[INFO] = &Harl::info;
	harlLevel[WARNING] = &Harl::warning;
	harlLevel[ERROR] = &Harl::error;

	for (int i = 0; i < LEVEL_SIZE; i++)
	{
		if (levels[i] == level)
		{
			(this->*harlLevel[i])();
			break;
		}
	}
}
