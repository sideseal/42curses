/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/09 22:48:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUI.hpp"

static struct timespec	req;
static struct timespec	rem;
static int				exitLoop;
struct Status			status;

void	check_leaks()
{
	system("leaks -- a.out");
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
	std::cout << status.formInfo.form << std::endl;
	if (status.formInfo.form != 0)
	{
		std::cout << status.formInfo.form->getName() << std::endl;
		std::cout << status.formInfo.message << std::endl;
	}
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

			//check();
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
		catch (char const* s)
		{
			initStatus();
			deleteInfo();
			status.isError = true;
			status.errorMessage = s;
		}
	}

	return 0;
}
