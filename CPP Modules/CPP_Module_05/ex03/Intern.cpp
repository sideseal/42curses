/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:22:42 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/04 01:33:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Intern::Intern()
{
	// nothing to do
}

Intern::Intern(Intern const& target)
{
	(void)target;
	// nothing to do
}

Intern&	Intern::operator=(Intern const& target)
{
	if (this != &target)
	{
		(void)target;
	}
	return *this;
}

Intern::~Intern()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

AForm*	Intern::makeForm
(std::string const& formName, std::string const& targetName)
{
	std::string const	nameArray[3] = {"presidential pardon",
										"robotomy request",
										"shrubbery creation"};
	AForm*				form;
	std::size_t			index;

	for (index = 0; index < Intern::FORM_SIZE; index++)
	{
		if (nameArray[index] == formName)
			break;
	}

	switch(index)
	{
		case Intern::PRESIDENTIAL_PARDON:
			form = new PresidentialPardonForm(targetName);
			break;
		case Intern::ROBOTOMY_REQUEST:
			form = new RobotomyRequestForm(targetName);
			break;
		case Intern::SHRUBBERY_CREATION:
			form = new ShrubberyCreationForm(targetName);
			break;
		default:
			std::cout << "Intern can't find " << targetName << std::endl;
			return 0;
	}

	std::cout << "Intern creates " << targetName << std::endl;

	return form;
}
