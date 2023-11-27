/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/27 22:44:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	setBureaucratInfo(std::string& bureaucratName, int& bureaucratGrade)
{
	std::string	bureaucratNameInput;
	std::string	bureaucratGradeInput;

	while (true)
	{
		std::cout << "Enter the bureaucrat name: ";
		std::getline(std::cin, bureaucratNameInput);

		if (bureaucratNameInput.empty())
		{
			std::cout << "Invalid input. Name cannot be empty.\n";
		}
		else
		{
			bureaucratName = bureaucratNameInput;
			break;
		}
	}

	while (true)
	{
		std::cout << "Enter the bureaucrat grade (1 to 150): ";
		std::getline(std::cin, bureaucratGradeInput);

		bool	isAllDigits = true;

		for (size_t i = 0; i < bureaucratGradeInput.length(); ++i)
		{
			if (!std::isdigit(bureaucratGradeInput[i])) {
				isAllDigits = false;
				break;
			}
		}

		std::istringstream	iss(bureaucratGradeInput);

		if (!isAllDigits || bureaucratGradeInput.empty() 
			|| (!(iss >> bureaucratGrade)))
		{
			std::cout << "Invalid input. Please enter a valid integer.\n";
		}
		else
		{
			break;
		}
	}
}

void	setFormInfo(std::string& formName, int& signGrade, int& executeGrade)
{
	std::string	formNameInput;
	std::string	formSignGradeInput;
	std::string formExecuteGradeInput;

	while (true)
	{
		std::cout << "Enter the form name: ";
		std::getline(std::cin, formNameInput);

		if (formNameInput.empty())
		{
			std::cout << "Invalid input. Name cannot be empty.\n";
		}
		else
		{
			formName = formNameInput;
			break;
		}
	}

	while (true)
	{
		std::cout << "Enter the form sign grade (1 to 150): ";
		std::getline(std::cin, formSignGradeInput);

		bool	isAllDigits = true;

		for (size_t i = 0; i < formSignGradeInput.length(); ++i)
		{
			if (!std::isdigit(formSignGradeInput[i])) {
				isAllDigits = false;
				break;
			}
		}

		std::istringstream	iss(formSignGradeInput);

		if (!isAllDigits || formSignGradeInput.empty() 
			|| (!(iss >> signGrade)))
		{
			std::cout << "Invalid input. Please enter a valid integer.\n";
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Enter the form execution grade (1 to 150): ";
		std::getline(std::cin, formExecuteGradeInput);

		bool	isAllDigits = true;

		for (size_t i = 0; i < formExecuteGradeInput.length(); ++i)
		{
			if (!std::isdigit(formExecuteGradeInput[i])) {
				isAllDigits = false;
				break;
			}
		}

		std::istringstream	iss(formExecuteGradeInput);

		if (!isAllDigits || formExecuteGradeInput.empty() 
			|| (!(iss >> executeGrade)))
		{
			std::cout << "Invalid input. Please enter a valid integer.\n";
		}
		else
		{
			break;
		}
	}
}

int	main()
{
	std::string	bureaucratName;
	int			bureaucratGrade;
	std::string	formName;
	int			formSignGrade;
	int			formExecuteGrade;

	setBureaucratInfo(bureaucratName, bureaucratGrade);
	setFormInfo(formName, formSignGrade, formExecuteGrade);

	try
	{
		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);
		std::cout << bureaucrat << std::endl;

		Form	form(formName, formSignGrade, formExecuteGrade);
		std::cout << form << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
