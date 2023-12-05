/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/05 22:11:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUI.hpp"

static struct timespec	req;
static struct timespec	rem;
static int				exitLoop;
struct Status			status;

void	signalHandler(__attribute__((unused)) int signum)
{
	exit(0);
}

void	delay()
{
	req.tv_nsec = 0.1 * 1000000000;
	nanosleep(&req, &rem);
}

int	main()
{
	signal(SIGINT, signalHandler);

	if (configureTerminal() == false)
	{
		return 1;
	}

	while (!exitLoop)
	{
		eraseTerminal();
		drawStage();
		updateStage();

		updatePopUp();

		int	key = readInput();
		controlKey(key);

		delay();
	}

	return 0;
}
