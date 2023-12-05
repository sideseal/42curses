/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/05 23:35:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define OK (1)
#define ERR (0)

#define MARGIN (10)
#define WIDTH (70)
#define HEIGHT (12)
#define BOX_WIDTH (40)
#define BOX_HEIGHT (6)

#define SELECT "\033[7m"
#define RESET "\033[0m"

enum eKey
{
	NONE,
	UP,
	DOWN,
	RIGHT,
	LEFT,
	ENTER,
	LETTER
};

enum eProcess
{
	DISABLE,
	SIGN,
	NAME,
	EXEC
};

enum eStage
{
	LOBBY,
	FORM,
	SHOW,
	MESSAGE
};

enum eMode
{
	MAKE,
	WATCH,
	QUIT
};

enum eForm
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENT,
	BACK
};

struct Status
{
	std::string		buffer;
	unsigned int	stage;
	unsigned int	mode;
	char			letter;
	int				select;
	bool			popUp;
	int				popUpProcess;
	bool			pressEnter;
	int				yesNo;
};

extern struct Status status;

void	resetTerminal();
bool	configureTerminal();
void	eraseTerminal();

int		readInput();
int		readKey(char* buf, int k);
void	controlKey(int key);

void	drawStage();
void	updateStage();
void	updatePopUp();

void	drawLobby();
void	drawForm();
void	popMessage();

#endif /* __GUI_HPP__ */
