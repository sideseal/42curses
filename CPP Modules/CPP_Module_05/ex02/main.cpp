/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/29 22:37:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

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

void	setFormInfo(std::string& formName, std::string const& formType)
{
	std::string	formNameInput;

	while (true)
	{
		std::cout << "Enter the " << formType << " name: ";
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
}

int	main()
{
	std::string	bureaucratName;
	int			bureaucratGrade;
	std::string	formName;

	setBureaucratInfo(bureaucratName, bureaucratGrade);
	setFormInfo(formName, "shrubberyCreationForm");

	try
	{
		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);
		std::cout << bureaucrat << std::endl;

		ShrubberyCreationForm	sForm(formName);
		std::cout << sForm << std::endl;

//		bureaucrat.signForm(sForm);
//		std::cout << sForm << std::endl;

		bureaucrat.executeForm(sForm);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
