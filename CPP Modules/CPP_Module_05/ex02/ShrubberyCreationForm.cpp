/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:09:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/28 22:56:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(std::string(), 145, 137)
{
	// nothing to do
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	throw(GradeTooHighException, GradeTooLowException) try
	: AForm(target, 145, 137)
{
	// nothing to do
}
catch (std::exception & e)
{
	throw;
}

ShrubberyCreationForm::ShrubberyCreationForm
(ShrubberyCreationForm const& target)
	: AForm(target.getName(), target.getSignGrade(), target.getExecuteGrade())
{
	// nothing to do
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=
(ShrubberyCreationForm const& target)
{
	if (this != &target)
	{
		_copyConstWarning("mName");
		this->mbIsSigned = target.getIsSigned();
		_copyConstWarning("mSignGrade");
		_copyConstWarning("mExecuteGrade");
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// nothing to do
}
