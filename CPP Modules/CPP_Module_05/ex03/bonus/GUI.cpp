/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/05 23:39:53 by gychoi           ###   ########.fr       */
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

	std::cout << "\033[?25l";
	atexit(resetTerminal);
	return OK;
}

void	eraseTerminal()
{
	std::cout << "\033[2J\033[H";
}

void	resetTerminal()
{
	std::cout << "\033[m";
	std::cout << "\033[?25h";
	eraseTerminal();
	std::cout << "GoodBye!" << std::endl;
	tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
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

	if (n == 1)
	{
		if (buf[0] == '\n')
		{
			return 5;
		}
		else
		{
			status.letter = buf[0];
			return 6;
		}
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

void	controlKey(int key)
{
	switch(key)
	{
		case UP:
			if (status.select > 0)
			{
				status.select--;
			}
			break;
		case DOWN:
			if (status.stage == LOBBY && status.select < 2)
			{
				status.select++;
			}
			else if (status.stage == FORM && status.select < 3)
			{
				status.select++;
			}
			break;
		case LEFT:
			status.yesNo = true;
			break;
		case RIGHT:
			status.yesNo = false;
			break;
		case ENTER:
			status.pressEnter = true;
			break;
	}
}

/* ************************************************************************** */
/*                                   Logic                                    */
/* ************************************************************************** */

void	drawStage()
{
	if (status.stage == LOBBY)
	{
		drawLobby();
	}
	else if (status.stage == FORM || status.stage == MESSAGE)
	{
		drawForm();
	}
	else if (status.stage == SHOW)
	{
		popMessage();
	}
}

void	updateStage()
{
	if (status.pressEnter == true)
	{
		if (status.stage == LOBBY)
		{
			if (status.select == MAKE)
			{
				status.stage = FORM;
				status.select = 0;
			}
			else if (status.select == WATCH)
			{
				status.stage = SHOW;
				status.select = 0;
			}
			else if (status.select == QUIT)
			{
				exit(0);
			}
		}
		else if (status.stage == FORM)
		{
			if (status.select == SHRUBBERY)
			{
				status.popUp = true;
				status.stage = MESSAGE;
				status.popUpProcess = SIGN;
			}
			else if (status.select == ROBOTOMY)
			{
				//
			}
			else if (status.select == PRESIDENT)
			{
				//
			}
			else if (status.select == BACK)
			{
				status.stage = LOBBY;
				status.select = 0;
			}
		}
		else if (status.stage == MESSAGE)
		{
			// check status.select
			if (status.popUpProcess == SIGN)
			{
				if (status.yesNo == true)
				{
					// making form
				}
				else
				{
					// skip form
					// for test
					status.popUp = false;
					status.stage = FORM;
					status.popUpProcess = DISABLE;
				}
				// status.popUpProcess = NAME;
			}
		}
		status.pressEnter = false;
	}
}

void	updatePopUp()
{
	if (status.popUp == true)
	{
		if (status.stage == FORM || status.stage == MESSAGE)
		{
			if (status.select == SHRUBBERY)
			{
				if (status.popUpProcess == SIGN)
				{
					popMessage();
				}
			}
		}
	}
}

/* ************************************************************************** */
/*                             Graphic Interfaces                             */
/* ************************************************************************** */

void	drawLobby()
{
	std::string const	menu[3] = { "Make Form", "Show Form", "Quit" };
	std::string const	welcome = "Welcome to Bureaucrat.net!";
	size_t				remainingLines = HEIGHT - 2;

	/*
	 * drawing top
	 */
	std::cout << "┌";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┐" << std::endl;

	/*
	 * drawing header
	 */
	size_t	sideSpace = (WIDTH - welcome.length()) / 2;
	size_t	startPos = sideSpace;
	size_t	endPos = sideSpace;

	std::cout << "│";
	for (size_t i = 0; i < startPos - 1; i++)
	{
		std::cout << " ";
	}
	std::cout << welcome;
	for (size_t i = 0; i < endPos - 1; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	std::cout << "├";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┤" << std::endl;
	remainingLines--;

	/*
	 * drawing menu section
	 */
	for (int i = 0; i < 3; i++)
	{
		if (status.select == i)
		{
			std::cout << "│ " << SELECT << menu[i];
		}
		else
		{
			std::cout << "│ " << menu[i];
		}

		for (size_t j = 0; j < WIDTH - menu[i].length() - 4; j++)
		{
			std::cout << " ";
		}
		std::cout << RESET << " │" << std::endl;
		remainingLines--;
	}

	for (size_t i = 0; i < remainingLines; i++)
	{
		std::cout << "│";
		for (size_t i = 0; i < WIDTH - 2; i++)
		{
			std::cout << " ";
		}
		std::cout << "│" << std::endl;
	}

	/*
	 * drawing bottom
	 */
	std::cout << "└";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┘" << std::endl;
}

void	drawForm()
{
	std::string const	menu[4] = { "Making shrubbery",
									"Requesting robotomy",
									"Pardon the president",
									"[Back]"};
	std::string const	welcome = "Choose your work";
	size_t				remainingLines = HEIGHT - 2;

	/*
	 * drawing top
	 */
	std::cout << "┌";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┐" << std::endl;

	/*
	 * drawing header
	 */
	size_t	sideSpace = (WIDTH - welcome.length()) / 2;
	size_t	startPos = sideSpace;
	size_t	endPos = sideSpace;

	std::cout << "│";
	for (size_t i = 0; i < startPos - 1; i++)
	{
		std::cout << " ";
	}
	std::cout << welcome;
	for (size_t i = 0; i < endPos - 1; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	std::cout << "├";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┤" << std::endl;
	remainingLines--;

	/*
	 * drawing menu section
	 */
	for (int i = 0; i < 4; i++)
	{
		if (status.select == i)
		{
			std::cout << "│ " << SELECT << menu[i];
		}
		else
		{
			std::cout << "│ " << menu[i];
		}

		for (size_t j = 0; j < WIDTH - menu[i].length() - 4; j++)
		{
			std::cout << " ";
		}
		std::cout << RESET << " │" << std::endl;
		remainingLines--;
	}

	for (size_t i = 0; i < remainingLines; i++)
	{
		std::cout << "│";
		for (size_t i = 0; i < WIDTH - 2; i++)
		{
			std::cout << " ";
		}
		std::cout << "│" << std::endl;
	}

	/*
	 * drawing bottom
	 */
	std::cout << "└";
	for (size_t i = 0; i < WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┘" << std::endl;
}

void	popMessage()
{
	int		startPosY = (HEIGHT - BOX_HEIGHT) / 2;
	int		startPosX = (WIDTH - BOX_WIDTH) / 2;
	size_t	remainingLines = BOX_HEIGHT - 2;

	/*
	 * drawing top
	 */
	std::cout << "\033[" << startPosY << ";" << startPosX << "H";
	std::cout << "┌";
	for (size_t i = 0; i < BOX_WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┐" << std::endl;

	/*
	 * drawing header
	 */
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::string const	message = "Do you want to sign this Form?";

	std::cout << "│ " << message;
	for (size_t i = 0; i < BOX_WIDTH - message.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << " │" << std::endl;
	remainingLines--;

	/*
	 * drawing body
	 */
	for (size_t i = 0; i < remainingLines - 1; i++)
	{
		std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
		std::cout << "│";
		for (size_t i = 0; i < BOX_WIDTH - 2; i++)
		{
			std::cout << " ";
		}
		std::cout << "│" << std::endl;
	}

	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│";
	for (size_t i = 0; i < MARGIN; i++)
	{
		std::cout << " ";
	}

	if (status.yesNo == true)
	{
		std::cout
		<< SELECT << "[YES]" << RESET
		<< "         "
		<< "[NO]";
	}
	else
	{
		std::cout
		<< "[YES]"
		<< "         "
		<< SELECT << "[NO]" << RESET;
	}

	for (size_t i = 0; i < MARGIN; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;

	/*
	 * drawing bottom
	 */
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "└";
	for (size_t i = 0; i < BOX_WIDTH - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┘" << std::endl;
}
