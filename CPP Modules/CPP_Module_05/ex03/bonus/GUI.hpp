/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/10 21:47:15 by gychoi           ###   ########.fr       */
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
	bool					renderStop;
	char					letter;
	unsigned short			stage;
	short					select;
	bool					create;
	short					popUp;
	bool					pressEnter;
	bool					yesNo;
	bool					pressLetter;
	bool					pressBackSpace;
	struct BureaucratInfo	bureaucratInfo;
	struct FormInfo			formInfo;
	std::string				shrubberyArray[8];
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

void	deleteBureaucrat();
void	deleteForm();

void	initStatus();
void	deleteInfo();
void	setStage();
void	updateStatus();
void	updatePopUp();
void	setFilename();

void	drawLobby();
void	drawCheck();
void	drawForm();
void	drawSignPopUp();
void	drawNamePopUp();
void	drawExecutePopUp();
void	drawShrubberyResultPopUp();
void	drawRobotomyResultPopUp();
void	drawLogin();
void	drawImage();
void	drawGoodbye();

void	printIfError();
void	changeRenderSpeed(float speed);
void	setFilename();
void	findAllShrubberyFiles(std::string shrubberyArray[]);
short	getArraySize(std::string const arr[], short size);

#endif /* __GUI_HPP__ */
