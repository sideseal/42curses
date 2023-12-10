/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/10 21:39:46 by gychoi           ###   ########.fr       */
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
	deleteBureaucrat();
	deleteForm();
	resetTerminal();
	exit(0);
}

void	delay()
{
	req.tv_nsec = status.renderSpeed * 1000000000;
	nanosleep(&req, &rem);
}

void	check(int key)
{
	std::cout << key << std::endl;
	std::cout << status.renderSpeed << std::endl;
	std::cout << status.renderStop << std::endl;
}

int	main()
{
	atexit(check_leaks);
	signal(SIGINT, signalHandler);

	if (configureTerminal() == false)
	{
		resetTerminal();
		return 1;
	}

	initStatus();
	eraseTerminal();
	drawLogin();
	while (!exitLoop)
	{
		try
		{
			int	key = readInput();
			controlKey(key);
			makeBuffer();
			updateStatus();
			setStage();
			updatePopUp();

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
