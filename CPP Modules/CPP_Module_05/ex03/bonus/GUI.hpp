/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/07 18:34:59 by gychoi           ###   ########.fr       */
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

#include "Bureaucrat.hpp"
#include "Intern.hpp"

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
	LETTER,
	BACKSPACE
};

enum eLogin
{
	ID,
	GRADE,
	CHECK_LOGIN
};

enum ePopUP
{
	DISABLE,
	SIGN,
	NAME,
	EXEC
};

enum eStage
{
	LOGIN,
	LOBBY,
	FORM,
	MESSAGE
};

enum eMode
{
	MAKE,
	LOGOUT,
	QUIT
};

enum eForm
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENT,
	BACK
};

struct FormInfo
{
	std::string	name;
	AForm*		form;
};

struct BureaucratInfo
{
	std::string	name;
	std::string	grade;
	Bureaucrat*	bureaucrat;
};

struct Status
{
	float					renderSpeed;
	std::string				buffer;
	char					letter;
	unsigned short			stage;
	unsigned short			mode;
	short					select;
	bool					create;
	bool					popUp;
	short					popUpProcess;
	bool					pressEnter;
	bool					yesNo;
	bool					pressLetter;
	bool					pressBackSpace;
	struct BureaucratInfo	bureaucratInfo;
	struct FormInfo			formInfo;
	bool					isError;
	std::string				errorMessage;
};

extern struct Status status;

void	resetTerminal();
bool	configureTerminal();
void	eraseTerminal();

int		readInput();
int		readKey(char* buf, int k);
void	controlKey(int key);
void	makeBuffer();

void	initStatus();
void	deleteInfo();
void	setStage();
void	updateStage();
void	updatePopUp();

void	printError();
void	drawLobby();
void	drawForm();
void	drawSignPopUp();
void	drawNamePopUp();
void	drawLogin();

#endif /* __GUI_HPP__ */
