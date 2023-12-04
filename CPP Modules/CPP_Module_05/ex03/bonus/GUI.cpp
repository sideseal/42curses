/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/04 21:58:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GUI.hpp"

static struct termios	oldTermios;
static struct termios	newTermios;

/* ************************************************************************** */
/*                             Terminal Interface                             */
/* ************************************************************************** */
bool	configureTerminal()
{
	if (tcgetattr(STDIN_FILENO, &oldTermios))
	{
		return ERR;
	}

	newTermios = oldTermios;

	newTermios.c_lflag &= ~(ICANON | ECHO);
	newTermios.c_cc[VMIN] = 0;
	newTermios.c_cc[VTIME] = 0;

	if (tcsetattr(STDIN_FILENO, TCSANOW, &newTermios))
	{
		return ERR;
	}
	return OK;
}

void	resetTerminal()
{
	std::cout << "\033[m";
	std::cout << "\033[?25h";
	std::cout << std::endl;
	tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
}

void	eraseTerminal()
{
	std::cout << "\033[2J\033[H";
}

/* ************************************************************************** */
/*                                 Key Input                                  */
/* ************************************************************************** */
int	readKey(char* buf, int k)
{
	if (buf[k] == '\033' && buf[k + 1] == '[')
	{
		switch (buf[k + 2])
		{
			case 'A': return 1;	// UP
			case 'B': return 2;	// DOWN
			case 'C': return 3;	// RIGHT
			case 'D': return 4;	// LEFT
		}
	}
	return 0;
}

int	readInput(void)
{
	char	buf[4096];
	int		n = read(STDIN_FILENO, buf, sizeof(buf));
	int		final_key = 0;

	//std::cout << n << std::endl;

	if (n == 1 && buf[0] == '\n')
	{
		return 5;
	}
	for (int k = 0; k <= n - 3; k += 3)
	{
		int	key = readKey(buf, k);
		if (key == 0)
		{
			continue;
		}
		final_key = key;
	}
	return final_key;
}
