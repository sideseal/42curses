/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/04 22:45:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUI.hpp"

static int	exitLoop;

static struct timespec	req;
static struct timespec	rem;

void	signalHandler(__attribute__((unused)) int signum)
{
	exitLoop = 1;
//	exit(0);
}

void	showMenu()
{
	std::string		menuItems[2] = { "create", "exit" };

	eraseTerminal();
}

void	printKey(int key)
{
	if (key == 1) std::cout << "UP" << std::endl;
	if (key == 2) std::cout << "DOWN" << std::endl;
	if (key == 3) std::cout << "RIGHT" << std::endl;
	if (key == 4) std::cout << "LEFT" << std::endl;
	if (key == 5) std::cout << "ENTER" << std::endl;
}

int	main()
{
	atexit(resetTerminal);
	signal(SIGINT, signalHandler);

	if (configureTerminal() == false)
	{
		return 1;
	}

	while (!exitLoop)
	{
		showMenu();

		int	key = readInput();
		printKey(key);

		req.tv_nsec = 0.1 * 1000000000;
		nanosleep(&req, &rem);
	}

	return 0;
}
