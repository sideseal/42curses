/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/09 22:36:45 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <dirent.h>
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

enum eStage
{
	LOGIN,
	LOBBY,
	CHECK,
	IMAGE,
	FORM,
	MESSAGE
};

enum eLobby
{
	MAKE,
	SHOW,
	LOGOUT,
	QUIT
};

enum eForm
{
	BACK,
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENT
};

enum ePopUP
{
	DISABLE,
	NAME,
	SIGN,
	EXECUTE,
	RESULT
};

struct FormInfo
{
	std::string	name;
	std::string	message;
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
	char					letter;
	unsigned short			stage;
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
	std::string				shrubberyArray[7];
	std::string				filename;
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
void	drawCheck();
void	drawForm();
void	drawSignPopUp();
void	drawNamePopUp();
void	drawExecutePopUp();
void	drawResultPopUp();
void	drawLogin();

void	changeRenderSpeed(float speed);
void	findAllShrubberyFiles(std::string shrubberyArray[]);

#endif /* __GUI_HPP__ */
