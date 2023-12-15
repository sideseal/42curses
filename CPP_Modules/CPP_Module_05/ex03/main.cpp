/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/11 23:05:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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

bool	askConfirm(std::string const& message)
{
	std::string	response;

	while (true)
	{
		std::cout << message << ": ";
		std::getline(std::cin, response);

		if (response == "y" || response == "Y" || response == "yes")
		{
			return true;
		}
		else if (response == "n" || response == "N" || response == "no")
		{
			return false;
		}
		else
		{
			continue;
		}
	}
	return false;
}

int	main()
{
	std::string	bureaucratName;
	int			bureaucratGrade;
	std::string	formName;

	try
	{
		Intern	intern;

		std::cout << "INFO: Creating ShrubberyCreationForm..." << std::endl;
		setFormInfo(formName, "ShrubberyCreationForm");
		AForm*	sForm = intern.makeForm("shrubbery creation", formName);
		std::cout << *sForm << '\n' << std::endl;

		std::cout << "INFO: Creating RobotomyRequestForm..." << std::endl;
		setFormInfo(formName, "RobotomyRequestForm");
		AForm*	rForm = intern.makeForm("robotomy request", formName);
		std::cout << *rForm << '\n' << std::endl;

		std::cout << "INFO: Creating PresidentialPardonForm..." << std::endl;
		setFormInfo(formName, "PresidentialPardonForm");
		AForm*	pForm = intern.makeForm("presidential pardon", formName);
		std::cout << *pForm << '\n' << std::endl;

		std::cout << "INFO: Creating Bureaucrat..." << std::endl;
		setBureaucratInfo(bureaucratName, bureaucratGrade);
		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);
		std::cout << bureaucrat << '\n' << std::endl;

		if (askConfirm("INFO: Do you want to sign ShrubberyCreationForm?"))
		{
			bureaucrat.signForm(*sForm);
		}
		else
		{
			// skipped
		}
		std::cout << *sForm << '\n' << std::endl;

		if (askConfirm("INFO: Do you want to sign RobotomyCreationForm?"))
		{
			bureaucrat.signForm(*rForm);
		}
		else
		{
			// skipped
		}
		std::cout << *rForm << '\n' << std::endl;

		if (askConfirm("INFO: Do you want to sign PresidentialPardonForm?"))
		{
			bureaucrat.signForm(*pForm);
		}
		else
		{
			// skippled
		}
		std::cout << *pForm << '\n' << std::endl;

		std::cout << "INFO: Executing ShrubberyCreationForm..." << std::endl;
		bureaucrat.executeForm(*sForm);

		std::cout << std::endl;

		std::cout << "INFO: Executing RobotomyCreationForm..." << std::endl;
		bureaucrat.executeForm(*rForm);

		std::cout << std::endl;

		std::cout << "INFO: Executing PresidentialPardonForm..." << std::endl;
		bureaucrat.executeForm(*pForm);

		std::cout << std::endl;

		std::cout << "INFO: Creating NuclearLaunchForm..." << std::endl;
		AForm*	nForm = intern.makeForm("nuclear launch", "Big Red Button");

		delete sForm;
		delete rForm;
		delete pForm;
		delete nForm;
	}
	catch (std::exception & e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
