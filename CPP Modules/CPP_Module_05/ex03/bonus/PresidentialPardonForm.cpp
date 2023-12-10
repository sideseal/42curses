/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:31:04 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/10 21:32:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

static void	_copyConstWarning(std::string const& variable);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm(std::string(), 25, 5)
{
	// nothing to do
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& targetName)
	: AForm(targetName, 25, 5)
{
	// nothing to do
}

PresidentialPardonForm::PresidentialPardonForm
(PresidentialPardonForm const& target)
	throw(GradeTooHighException, GradeTooLowException) try
	: AForm(target.getName(), target.getSignGrade(), target.getExecuteGrade())
{
	// nothing to do
}
catch (std::exception & e)
{
	throw;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=
(PresidentialPardonForm const& target)
{
	if (this != &target)
	{
		_copyConstWarning("mName");
		this->setIsSigned(target.getIsSigned());
		_copyConstWarning("mSignGrade");
		_copyConstWarning("mExecuteGrade");
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */
void	PresidentialPardonForm::beSigned(Bureaucrat const& bureaucrat)
throw(GradeTooLowException)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
	{
		throw GradeTooLowException("Bureaucrat's grade is too low!");
	}
	else
	{
		this->setIsSigned(true);
	}
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
throw(GradeTooLowException, FormNotSignedException, char const*)
{
	if (this->getExecuteGrade() < executor.getGrade())
	{
		throw GradeTooLowException("Bureaucrat's grade is too low!");
	}
	else if (this->getIsSigned() == false)
	{
		throw FormNotSignedException("Form is not signed!");
	}
	else
	{
		std::string	message = "Well done! "
							+ this->getName()
							+ " has been pardoned by Zaphod Beeblebrox!";

		throw message.c_str();
	}
}

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
PresidentialPardonForm::GradeTooHighException::GradeTooHighException()
	: mMessage("PresidentialPardonForm::GradeTooHighException")
{
	// nothing to do
}

PresidentialPardonForm::GradeTooHighException::GradeTooHighException
(std::string const& msg)
	: mMessage("PresidentialPardonForm::GradeTooHighException: " + msg)
{
	// nothing to do
}

PresidentialPardonForm::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

PresidentialPardonForm::GradeTooHighException&
PresidentialPardonForm::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

PresidentialPardonForm::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	PresidentialPardonForm::GradeTooHighException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char*	PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*              GradeTooLowException : Constructor & Destructor               */
/* ************************************************************************** */
PresidentialPardonForm::GradeTooLowException::GradeTooLowException()
	: mMessage("PresidentialPardonForm::GradeTooLowException")
{
	// nothing to do
}

PresidentialPardonForm::GradeTooLowException::GradeTooLowException
(std::string const& msg)
	: mMessage("PresidentialPardonForm::GradeTooLowException: " + msg)
{
	// nothing to do
}

PresidentialPardonForm::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

PresidentialPardonForm::GradeTooLowException&
PresidentialPardonForm::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

PresidentialPardonForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	PresidentialPardonForm::GradeTooLowException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*             FormNotSignedException : Constructor & Destructor              */
/* ************************************************************************** */
PresidentialPardonForm::FormNotSignedException::FormNotSignedException()
	: mMessage("PresidentialPardonForm::FormNotSignedException")
{
	// nothing to do
}

PresidentialPardonForm::FormNotSignedException::FormNotSignedException
(std::string const& msg)
	: mMessage("PresidentialPardonForm::FormNotSignedException: " + msg)
{
	// nothing to do
}

PresidentialPardonForm::FormNotSignedException::FormNotSignedException
(FormNotSignedException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

PresidentialPardonForm::FormNotSignedException&
PresidentialPardonForm::FormNotSignedException::operator=
(FormNotSignedException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

PresidentialPardonForm::FormNotSignedException::~FormNotSignedException()
throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  FormNotSigendException : Getter Function                  */
/* ************************************************************************** */
std::string const&	PresidentialPardonForm::FormNotSignedException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 FormNotSigendException : Function Override                 */
/* ************************************************************************** */
const char*	PresidentialPardonForm::FormNotSignedException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */

std::ostream&	operator<<
(std::ostream& os, PresidentialPardonForm const& target)
{
	std::string	isAFormSigned = target.getIsSigned() ? "true" : "false";

	os << target.getName()
	<< ", PresidentialPardonForm signed " << isAFormSigned
	<< ", PresidentialPardonForm sign grade " << target.getSignGrade()
	<< ", PresidentialPardonForm execution grade " << target.getExecuteGrade()
	<< ".";
	return os;
}

/* ************************************************************************** */
/*                              Helper Functions                              */
/* ************************************************************************** */
static void	_copyConstWarning(std::string const& variable)
{
	std::cout << "INFO: You are trying to overwrite a const type variable: " <<
		variable << ". " << "This operation will be ignored." << std::endl;
}
