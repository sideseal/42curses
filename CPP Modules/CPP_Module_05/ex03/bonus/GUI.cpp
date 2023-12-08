/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/09 03:18:06 by gychoi           ###   ########.fr       */
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
			if (status.stage == LOBBY && status.select < 3)
			{
				status.select++;
			}
			else if (status.stage == FORM && status.select < 3)
			{
				status.select++;
			}
			else if (status.stage == CHECK && status.select < 7)
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
			if (status.popUpProcess == NAME)
			{
				if (status.pressBackSpace == true)
				{
					status.formInfo.name.pop_back();
				}
				else if (status.formInfo.name.length() < 8)
				{
					status.formInfo.name += status.letter;
				}
			}
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
	status.letter = '\0';
	//	need to keep status.stage info
	status.select = 0;
	status.create = false;
	status.popUp = false;
	status.popUpProcess = 0;
	status.pressEnter = false;
	status.yesNo = false;
	status.pressLetter = false;
	status.pressBackSpace = false;
	// need to keey shrubberyArray and filename
	status.isError = false;
	status.errorMessage.clear();
}

void	deleteInfo()
{
	if (status.stage == LOGIN)
	{
		deleteBureaucrat();
	}
	else if (status.stage == FORM)
	{
		deleteForm();
	}
}

void	setStage()
{
	switch (status.stage)
	{
		case LOGIN:
			changeRenderSpeed(0.03f);
			drawLogin();
			makeBuffer();
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
			makeBuffer();
			break;
		default:
			break;
	}
}

void	updateStage()
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
					initStatus();
					status.stage = IMAGE;
					break;
			}
			break;
		case IMAGE:
			break;
		case FORM:
			switch (status.select)
			{
				case BACK:
					initStatus();
					status.stage = LOBBY;
					break;
				case SHRUBBERY:
					status.popUp = true;
					status.stage = MESSAGE;
					status.popUpProcess = SIGN;
					break;
				case ROBOTOMY:
					// not developed
					break;
				case PRESIDENT:
					// not developed
					break;
				default:
					break;
			}
			break;
		case MESSAGE:
			switch (status.popUpProcess)
			{
				case SIGN:
					if (status.yesNo == true)
					{
						changeRenderSpeed(0.03f);
						status.popUpProcess = NAME;
					}
					else
					{
						initStatus();
						status.stage = FORM;
					}
					break;
				case NAME:
					changeRenderSpeed(0.1f);
					createForm();
					signForm();
					status.yesNo = false;
					status.popUpProcess = EXECUTE;
					break;
				case EXECUTE:
					if (status.yesNo == true)
					{
						executeForm();
						status.popUpProcess = RESULT;
					}
					else
					{
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
	if (status.popUp == true)
	{
		if (status.stage == FORM || status.stage == MESSAGE)
		{
			if (status.select == SHRUBBERY)
			{
				if (status.popUpProcess == SIGN)
				{
					drawSignPopUp();
				}
				else if (status.popUpProcess == NAME)
				{
					drawNamePopUp();
				}
				else if (status.popUpProcess == EXECUTE)
				{
					drawExecutePopUp();
				}
				else if (status.popUpProcess == RESULT)
				{
					drawResultPopUp();
				}
			}
		}
	}
}

void	setFilename()
{
	status.filename = status.shrubberyArray[status.select];
}

/* ************************************************************************** */
/*                             Graphic Interfaces                             */
/* ************************************************************************** */

void	printError()
{
	if (status.isError == true)
	{
		std::cout << status.errorMessage << std::endl;
	}
}

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
		status.shrubberyArray[i] = shrubberyArray[i + 1];
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
		else if (status.select == ID
				&& i == status.formInfo.name.length())
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

void	drawResultPopUp()
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

/* ************************************************************************** */
/*                                   Utils                                    */
/* ************************************************************************** */

void	changeRenderSpeed(float speed)
{
	status.renderSpeed = speed;
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
