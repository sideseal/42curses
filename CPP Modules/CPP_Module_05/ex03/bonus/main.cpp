/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/07 18:34:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUI.hpp"

static struct timespec	req;
static struct timespec	rem;
static int				exitLoop;
struct Status			status;

void	check_leaks()
{
	system("leaks a.out");
}

void	signalHandler(__attribute__((unused)) int signum)
{
	exit(0);
}

void	delay()
{
	req.tv_nsec = status.renderSpeed * 1000000000;
	nanosleep(&req, &rem);
}

void	check()
{
//	std::cout << status.bureaucratInfo.bureaucrat << std::endl;
//	if (status.bureaucratInfo.bureaucrat != 0)
//	{
//		std::cout << status.bureaucratInfo.bureaucrat->getName() << std::endl;
//		std::cout << status.bureaucratInfo.bureaucrat->getGrade() << std::endl;
//	}
}

int	main()
{
	atexit(check_leaks);
	signal(SIGINT, signalHandler);

	if (configureTerminal() == false)
	{
		return 1;
	}

	initStatus();
	while (!exitLoop)
	{
		try
		{
			eraseTerminal();
			setStage();
			updateStage();
			updatePopUp();

			check();
			printError();

			int	key = readInput();
			controlKey(key);

			delay();
		}
		catch (std::exception & e)
		{
			initStatus();
			deleteInfo();
			status.isError = true;
			status.errorMessage = e.what();
		}
	}

	return 0;
}
