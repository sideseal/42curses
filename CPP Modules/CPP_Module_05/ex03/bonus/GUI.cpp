/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/10 22:05:03 by gychoi           ###   ########.fr       */
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
	return OK;
}

void	eraseTerminal()
{
	std::cout << "\033[2J\033[H";
}

// remove bureaucrat and form
void	resetTerminal()
{
	std::cout << "\033[m";
	std::cout << "\033[?25h";
	eraseTerminal();
	drawGoodbye();
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

	if (n < 0)
	{
		status.isError = true;
		status.errorMessage = "FATAL: Cannot read key";
		return 42;
	}
	else if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		if (buf[0] == '\n')
		{
			return 5;
		}
		else if (static_cast<int>(buf[0]) == 8
				|| static_cast<int>(buf[0]) == 127)
		{
			return 7;
		}
		else
		{
			status.letter = buf[0];
			return 6;
		}
	}
	else
	{
		for (int k = 0; k <= n - 3; k += 3)
		{
			int	key = readKey(buf, k);
			if (key == 0)
			{
				continue;
			}
			final_key = key;
		}
	}
	return final_key;
}

void	controlKey(int key)
{
	switch(key)
	{
		case NONE:
			break;
		case UP:
			if (status.select > 0)
			{
				status.select--;
			}
			break;
		case DOWN:
			if ((status.stage == LOBBY || status.stage == FORM)
				&& status.select < 3)
			{
				status.select++;
			}
			else if (status.stage == CHECK
					 && status.select
					 < getArraySize(status.shrubberyArray, 8) - 1)
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
		case LETTER:
			status.pressLetter = true;
			break;
		case BACKSPACE:
			status.pressLetter = true;
			status.pressBackSpace = true;
			break;
		default:
			break;
	}
	status.renderStop = false;
}

void	makeBuffer()
{
	if (status.pressLetter == false)
	{
		return;
	}

	switch(status.stage)
	{
		case LOGIN:
			switch(status.select)
			{
				case ID:
					if (status.pressBackSpace == true)
					{
						status.bureaucratInfo.name.pop_back();
					}
					else if (status.bureaucratInfo.name.length() < 8)
					{
						status.bureaucratInfo.name += status.letter;
					}
					break;
				case GRADE:
					if (status.pressBackSpace == true)
					{
						status.bureaucratInfo.grade.pop_back();
					}
					else if (status.bureaucratInfo.grade.length() < 3)
					{
						status.bureaucratInfo.grade += status.letter;
					}
					break;
				default:
					break;
			}
			break;
		case MESSAGE:
			if (status.popUp == NAME && status.pressBackSpace == true)
			{
				status.formInfo.name.pop_back();
			}
			else if (status.popUp == NAME
					 && status.formInfo.name.length() < 8)
			{
				status.formInfo.name += status.letter;
			}
			break;
		default:
			break;
	}
	status.pressLetter = false;
	status.pressBackSpace = false;
}

/* ************************************************************************** */
/*                                 Mandatory                                  */
/* ************************************************************************** */

bool	createBureaucrat()
{
	status.create = true;

	for (size_t i = 0; i < status.bureaucratInfo.grade.length(); ++i)
	{
		if (!std::isdigit(status.bureaucratInfo.grade[i]))
		{
			status.create = false;
			break;
		}
	}

	if (status.create == false)
	{
		status.isError = true;
		status.errorMessage = "ERROR: Grade must be a number";
	}
	return status.create;
}

void	makeBureaucrat()
{
	std::string const&	name = status.bureaucratInfo.name;
	int					grade = std::atoi(status.bureaucratInfo.grade.c_str());

	Bureaucrat*	bureaucrat = new Bureaucrat(name, grade);

	status.bureaucratInfo.bureaucrat = bureaucrat;
	status.bureaucratInfo.name.clear();
	status.bureaucratInfo.grade.clear();
}

void	deleteBureaucrat()
{
	status.bureaucratInfo.name.clear();
	status.bureaucratInfo.grade.clear();
	delete status.bureaucratInfo.bureaucrat;
	status.bureaucratInfo.bureaucrat = 0;
}

void	createForm()
{
	Intern	intern;

	switch (status.select)
	{
		case SHRUBBERY:
			status.formInfo.form = intern.makeForm("shrubbery creation",
												   status.formInfo.name);
			break;
		case ROBOTOMY:
			status.formInfo.form = intern.makeForm("robotomy request",
												   status.formInfo.name);
			break;
		case PRESIDENT:
			status.formInfo.form = intern.makeForm("presidential pardon",
												   status.formInfo.name);
			break;
		default:
			break;
	}
}

void	signForm()
{
	try
	{
		if (status.bureaucratInfo.bureaucrat == 0)
		{
			throw std::logic_error("ERROR: bureaucrat not found");
		}
		else
		{
			status.bureaucratInfo.bureaucrat->signForm(*status.formInfo.form);
		}
	}
	catch (std::exception & e)
	{
		initStatus();
		status.stage = FORM;
		throw;
	};
}

void	executeForm()
{
	try
	{
		if (status.bureaucratInfo.bureaucrat == 0)
		{
			throw std::logic_error("ERROR: bureaucrat not found");
		}
		else
		{
			status.bureaucratInfo.bureaucrat->executeForm
				(*status.formInfo.form);
		}
	}
	catch (std::exception & e)
	{
		initStatus();
		status.stage = FORM;
		throw;
	}
	catch (char const* s)
	{
		status.formInfo.message = s;
	};
}

void	deleteForm()
{
	status.formInfo.name.clear();
	status.formInfo.message.clear();
	delete status.formInfo.form;
	status.formInfo.form = 0;
}

/* ************************************************************************** */
/*                                   Logic                                    */
/* ************************************************************************** */

void	initStatus()
{
	status.renderSpeed = 0.1f;
	status.renderStop = false;
	status.letter = '\0';
	//	need to keep status.stage info
	status.select = 0;
	status.create = false;
	status.popUp = false;
	status.pressEnter = false;
	status.yesNo = false;
	status.pressLetter = false;
	status.pressBackSpace = false;
	// need to keey shrubberyArray
	status.filename.clear();
	status.isError = false;
	status.errorMessage.clear();
}

void	deleteInfo()
{
	switch (status.stage)
	{
		case LOGIN:
			deleteBureaucrat();
			break;
		case FORM:
			deleteForm();
			break;
		default:
			break;
	}
}

void	setStage()
{
	if (status.renderStop == true)
	{
		return;
	}

	eraseTerminal();

	switch (status.stage)
	{
		case LOGIN:
			drawLogin();
			break;
		case LOBBY:
			drawLobby();
			break;
		case CHECK:
			drawCheck();
			break;
		case IMAGE:
			drawImage();
			break;
		case FORM:
			drawForm();
			break;
		case MESSAGE:
			drawForm();
			break;
		default:
			break;
	}
	printIfError();
	status.renderStop = true;
}

void	updateStatus()
{
	if (status.pressEnter == false)
	{
		return;
	}

	switch (status.stage)
	{
		case LOGIN:
			switch (status.select)
			{
				case ID:
					status.select = GRADE;
					break;
				case GRADE:
					status.select = CHECK_LOGIN;
					break;
				case CHECK_LOGIN:
					if (status.yesNo == true)
					{
						if (createBureaucrat() == true)
						{
							makeBureaucrat();
							status.stage = LOBBY;
							initStatus();
						}
						else
						{
							status.select = GRADE;
							status.bureaucratInfo.grade.clear();
						}
					}
					else
					{
						deleteBureaucrat();
						deleteForm();
						resetTerminal();
						exit(0);
					}
					break;
				default:
					break;
			}
			break;
		case LOBBY:
			switch (status.select)
			{
				case MAKE:
					initStatus();
					status.stage = FORM;
					break;
				case SHOW:
					initStatus();
					status.stage = CHECK;
					break;
				case LOGOUT:
					initStatus();
					deleteBureaucrat();
					status.stage = LOGIN;
					break;
				case QUIT:
					deleteBureaucrat();
					deleteForm();
					resetTerminal();
					exit(0);
					break;
				default:
					break;
			}
			break;
		case CHECK:
			switch (status.select)
			{
				case BACK:
					initStatus();
					status.stage = LOBBY;
					break;
				default:
					setFilename();
					status.stage = IMAGE;
					break;
			}
			break;
		case IMAGE:
			status.stage = CHECK;
			break;
		case FORM:
			switch (status.select)
			{
				case BACK:
					initStatus();
					status.stage = LOBBY;
					break;
				case SHRUBBERY:
					initStatus();
					status.select = SHRUBBERY;
					status.popUp = NAME;
					status.stage = MESSAGE;
					break;
				case ROBOTOMY:
					initStatus();
					status.select = ROBOTOMY;
					status.popUp = NAME;
					status.stage = MESSAGE;
					break;
				case PRESIDENT:
					initStatus();
					status.select = PRESIDENT;
					status.popUp = NAME;
					status.stage = MESSAGE;
					break;
					break;
				default:
					break;
			}
			break;
		case MESSAGE:
			switch (status.popUp)
			{
				case DISABLE:
					break;
				case NAME:
					changeRenderSpeed(0.1f);
					createForm();
					status.yesNo = false;
					status.popUp = SIGN;
					break;
				case SIGN:
					if (status.yesNo == true)
					{
						signForm();
					}
					status.yesNo = false;
					status.popUp = EXECUTE;
					break;
				case EXECUTE:
					if (status.yesNo == true)
					{
						executeForm();
						status.popUp = RESULT;
					}
					else
					{
						deleteForm();
						initStatus();
						status.stage = FORM;
					}
					break;
				case RESULT:
					deleteForm();
					initStatus();
					status.stage = FORM;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	status.pressEnter = false;
}

void	updatePopUp()
{
	if (status.popUp == DISABLE
		|| (status.stage != FORM && status.stage != MESSAGE))
	{
		return;
	}

	switch (status.select)
	{
		case SHRUBBERY:
			switch (status.popUp)
			{
				case NAME:
					drawNamePopUp();
					break;
				case SIGN:
					drawSignPopUp();
					break;
				case EXECUTE:
					drawExecutePopUp();
					break;
				case RESULT:
					drawShrubberyResultPopUp();
					break;
				default:
					break;
			}
			break;
		case ROBOTOMY:
			switch (status.popUp)
			{
				case NAME:
					drawNamePopUp();
					break;
				case SIGN:
					drawSignPopUp();
					break;
				case EXECUTE:
					drawExecutePopUp();
					break;
				case RESULT:
					drawRobotomyResultPopUp();
					break;
				default:
					break;
			}
			break;
		case PRESIDENT:
			switch (status.popUp)
			{
				case NAME:
					drawNamePopUp();
					break;
				case SIGN:
					drawSignPopUp();
					break;
				case EXECUTE:
					drawExecutePopUp();
					break;
				case RESULT:
					drawRobotomyResultPopUp();
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

/* ************************************************************************** */
/*                             Graphic Interfaces                             */
/* ************************************************************************** */

void	drawLobby()
{
	std::string const	menu[4] = { "Make Form",
									"Verify Task",
									"Logout",
									"Quit" };
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

void	drawCheck()
{
	std::string 		shrubberyArray[8];
	std::string const	banner = "Verify administration work";
	size_t				remainingLines = HEIGHT - 2;

	shrubberyArray[0] = "[Back]";
	findAllShrubberyFiles(shrubberyArray);

	for (size_t i = 0; i < 8; i++)
	{
		status.shrubberyArray[i] = shrubberyArray[i];
	}
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
	size_t	sideSpace = (WIDTH - banner.length()) / 2;
	size_t	startPos = sideSpace;
	size_t	endPos = sideSpace;

	std::cout << "│";
	for (size_t i = 0; i < startPos - 1; i++)
	{
		std::cout << " ";
	}
	std::cout << banner;
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

	for (int i = 0; i < 8; i++)
	{
		if (status.select == i)
		{
			std::cout << "│ " << SELECT << shrubberyArray[i];
		}
		else
		{
			std::cout << "│ " << shrubberyArray[i];
		}

		for (size_t j = 0; j < WIDTH - shrubberyArray[i].length() - 4; j++)
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
	std::string const	menu[4] = {"[Back]",
								   "Making shrubbery",
								   "Requesting robotomy",
								   "Pardon the president"};
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

void	drawSignPopUp()
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
	remainingLines -= 2;

	/*
	 * drawing body
	 */
	for (size_t i = 0; i < remainingLines; i++)
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

void	drawNamePopUp()
{
	int		startPosY = (HEIGHT - BOX_HEIGHT) / 2;
	int		startPosX = (WIDTH - BOX_WIDTH) / 2;
	size_t	remainingLines = BOX_HEIGHT - 2;

	changeRenderSpeed(0.03f);
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
	std::string const	message = "Enter the form name";

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
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│ Name: ";

	for (size_t i = 0; i < 8; i++)
	{
		if (i < status.formInfo.name.length())
		{
			std::cout << status.formInfo.name[i];
		}
		else if (i == status.formInfo.name.length())
		{
			std::cout << "▆";
		}
		else
		{
			std::cout << "_";
		}
	}

	for (size_t i = 0; i < BOX_WIDTH - 2 - 15; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	for (size_t i = 0; i < remainingLines; i++)
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
	std::string const	message2 = "Press [Enter] to submit";

	std::cout << "│ ";
	for (size_t i = 0; i < BOX_WIDTH - message2.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << message2 << " │" << std::endl;

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

void	drawExecutePopUp()
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
	std::string const	message = "Do you want to execute this Form?";

	std::cout << "│ " << message;
	for (size_t i = 0; i < BOX_WIDTH - message.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << " │" << std::endl;
	remainingLines -= 2;

	/*
	 * drawing body
	 */
	for (size_t i = 0; i < remainingLines; i++)
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

void	drawShrubberyResultPopUp()
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
	std::string const	message = "Message";

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
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│";
	for (size_t i = 0; i < BOX_WIDTH - 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	size_t	msgLen = status.formInfo.message.length();
	size_t	printLen = BOX_WIDTH - 4;

	for (size_t i = 0; i < msgLen; i += printLen)
	{
		std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
		std::cout << "│ ";
		for (size_t j = 0; j < BOX_WIDTH - 4 && i + j < msgLen; j++)
		{
			std::cout << status.formInfo.message[i + j];
		}
		for (int k = 0; k < static_cast<int>(printLen - (msgLen - i)); k++)
		{
			std::cout << " ";
		}
		std::cout << " │" << std::endl;
		if (remainingLines > 1)
		{
			remainingLines--;
		}
	}

	for (size_t i = 0; i < remainingLines; i++)
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
	std::string const	message2 = "Press [Enter] to continue";

	std::cout << "│ ";
	for (size_t i = 0; i < BOX_WIDTH - message2.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << message2 << " │" << std::endl;

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

void	drawRobotomyResultPopUp()
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
	std::string const	message = "Message";

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
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│";
	for (size_t i = 0; i < BOX_WIDTH - 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	size_t	msgLen = status.formInfo.message.length();
	size_t	printLen = BOX_WIDTH - 4;

	for (size_t i = 0; i < msgLen; i += printLen)
	{
		std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
		std::cout << "│ ";
		for (size_t j = 0; j < BOX_WIDTH - 4 && i + j < msgLen; j++)
		{
			std::cout << status.formInfo.message[i + j];
		}
		for (int k = 0; k < static_cast<int>(printLen - (msgLen - i)); k++)
		{
			std::cout << " ";
		}
		std::cout << " │" << std::endl;
		if (remainingLines > 1)
		{
			remainingLines--;
		}
	}

	for (size_t i = 0; i < remainingLines; i++)
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
	std::string const	message2 = "Press [Enter] to continue";

	std::cout << "│ ";
	for (size_t i = 0; i < BOX_WIDTH - message2.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << message2 << " │" << std::endl;

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

void	drawLogin()
{
	int		startPosY = (HEIGHT - BOX_HEIGHT) / 2;
	int		startPosX = (WIDTH - BOX_WIDTH) / 2;
	size_t	remainingLines = BOX_HEIGHT - 2;

	changeRenderSpeed(0.03f);
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
	std::string const	message = "Login";

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
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│ Name: ";

	for (size_t i = 0; i < 8; i++)
	{
		if (i < status.bureaucratInfo.name.length())
		{
			std::cout << status.bureaucratInfo.name[i];
		}
		else if (status.select == ID
				&& i == status.bureaucratInfo.name.length())
		{
			std::cout << "▆";
		}
		else
		{
			std::cout << "_";
		}
	}

	for (size_t i = 0; i < BOX_WIDTH - 2 - 15; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│ Grade: ";

	for (size_t i = 0; i < 3; i++)
	{
		if (i < status.bureaucratInfo.grade.length())
		{
			std::cout << status.bureaucratInfo.grade[i];
		}
		else if (status.select == GRADE
				&& i == status.bureaucratInfo.grade.length())
		{
			std::cout << "▆";
		}
		else
		{
			std::cout << "_";
		}
	}

	for (size_t i = 0; i < BOX_WIDTH - 2 - 11; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;
	remainingLines--;

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
	for (size_t i = 0; i < MARGIN - 2; i++)
	{
		std::cout << " ";
	}

	if (status.select == CHECK_LOGIN)
	{
		if (status.yesNo == true)
		{
			std::cout
			<< SELECT << "[Login]" << RESET
			<< "         "
			<< "[Quit]";
		}
		else
		{
			std::cout
			<< "[Login]"
			<< "         "
			<< SELECT << "[Quit]" << RESET;
		}
	}
	else
	{
		std::cout << "[Login]" << "         " << "[Quit]";
	}

	for (size_t i = 0; i < MARGIN - 2; i++)
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

void	drawImage()
{
	std::ifstream	file(status.filename);

	if (!file.is_open())
	{
		throw "Cannot open the file";
	}

	std::string		line;
	size_t			lineCount = 0;
	size_t			lineLength = 0;

	while (getline(file, line))
	{
		size_t	len = line.length();

		if (len > lineLength)
		{
			lineLength = len;
		}
		lineCount++;
	}
	lineLength += 2;
	file.clear();
	file.seekg(0, file.beg);
	file.close();

	int		startPosY = static_cast<int>((HEIGHT - lineCount) / 2) < 0
						? (HEIGHT - BOX_HEIGHT) / 2
						: (HEIGHT - lineCount) / 2;
	int		startPosX = static_cast<int>((WIDTH - lineLength) / 2) < 0
						? (WIDTH - BOX_WIDTH) / 2
						: (WIDTH - lineLength) / 2;

	/*
	 * drawing top
	 */
	std::cout << "\033[" << startPosY << ";" << startPosX << "H";
	std::cout << "┌";
	for (size_t i = 0; i < lineLength - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┐" << std::endl;

	/*
	 * drawing body
	 */
	file.open(status.filename);

	if (!file.is_open())
	{
		throw "Cannot open the file";
	}

	while (getline(file, line))
	{
		std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
		std::cout << "│";
		std::cout << line;
		if (line.length() < lineLength)
		{
			for (size_t i = 0; i < lineLength - line.length() - 2; i++)
			{
				std::cout << " ";
			}
		}
		std::cout << "│" << std::endl;
	}
	file.close();

	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "│";
	for (size_t i = 0; i < lineLength - 2; i++)
	{
		std::cout << " ";
	}
	std::cout << "│" << std::endl;

	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::string const	message2 = "Press [Enter] to close";

	std::cout << "│ ";
	for (size_t i = 0; i < lineLength - message2.length() - 4; i++)
	{
		std::cout << " ";
	}
	std::cout << message2 << " │" << std::endl;

	/*
	 * drawing bottom
	 */
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "└";
	for (size_t i = 0; i < lineLength - 2; i++)
	{
		std::cout << "─";
	}
	std::cout << "┘" << std::endl;
}

void	drawGoodbye()
{
	int		startPosY = (HEIGHT - BOX_HEIGHT) / 2;
	int		startPosX = (WIDTH - BOX_WIDTH) / 2;

	std::cout << "\033[" << startPosY << ";" << startPosX << "H";
	std::cout << "Goodbye!" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "                       000000000" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "                    00          00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "      00000       00              00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "     0     0    00     00    00     00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "     0     0   00      00    00       00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "     0    0  00        00    00        00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "      0   0   0                         00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "    000000000000                        00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "   0            0 00             00     00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "  00            0  00            00     00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << " 00   00000000000    00        00       00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << " 0               0     0000000         00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << " 00              0                    00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "  0   000000000000                   00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "  00           0  00                00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "   000000000000     00            00" << std::endl;
	std::cout << "\033[" << ++startPosY << ";" << startPosX << "H";
	std::cout << "                       00000000000" << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                   Utils                                    */
/* ************************************************************************** */

void	printIfError()
{
	if (status.isError == true)
	{
		std::cout << status.errorMessage << std::endl;
	}
}

void	changeRenderSpeed(float speed)
{
	status.renderSpeed = speed;
}

void	setFilename()
{
	status.filename = status.shrubberyArray[status.select];
}

void	findAllShrubberyFiles(std::string shrubberyArray[])
{
	DIR*			dir;
	struct dirent*	ent;
	int				index = 0;

	if ((dir = opendir(".")) == NULL)
		throw "Could not open directory";

	while ((ent = readdir(dir)) != NULL)
	{
		size_t	len = strlen(ent->d_name);
		if (len > 10 && std::string(ent->d_name + len - 10) == "_shrubbery")
		{
			shrubberyArray[(index++ % 7) + 1] = std::string(ent->d_name);
		}
	}
	closedir(dir);
}

short	getArraySize(std::string const arr[], short size)
{
	size_t	count = 0;

	for (size_t i = 0; i < static_cast<size_t>(size); i++)
	{
		if (!arr[i].empty())
		{
			count++;
		}
	}

	return static_cast<short>(count);
}
