/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:24:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/29 21:27:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void	_copyConstWarning(std::string const& object);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
Form::Form()
	: mName(std::string()),
	  mbIsSigned(false),
	  mSignGrade(0),
	  mExecuteGrade(0)
{
	// nothing to do
}

Form::Form(std::string const& name, int signGrade, int executeGrade)
	: mName(name),
	  mbIsSigned(false),
	  mSignGrade(signGrade),
	  mExecuteGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || executeGrade > 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		// nothing to do
	}
}

Form::Form(Form const& target)
	: mName(target.getName()),
	  mbIsSigned(false),
	  mSignGrade(target.getSignGrade()),
	  mExecuteGrade(target.getExecuteGrade())
{
	// nothing to do
}

Form&	Form::operator=(Form const& target)
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

Form::~Form()
{
	// nothing to do
}

/* ************************************************************************** */
/*                         Getter & Setter Functions                          */
/* ************************************************************************** */
std::string const&	Form::getName() const
{
	return this->mName;
}

bool	Form::getIsSigned() const
{
	return this->mbIsSigned;
}

int	Form::getSignGrade() const
{
	return this->mSignGrade;
}

int	Form::getExecuteGrade() const
{
	return this->mExecuteGrade;
}

void	Form::setIsSigned(bool isSigned)
{
	this->mbIsSigned = isSigned;
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */
void	Form::beSigned(Bureaucrat const& bureaucrat)
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

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
Form::GradeTooHighException::GradeTooHighException()
	: mMessage("Form::GradeTooHighException")
{
	// nothing to do
}

Form::GradeTooHighException::GradeTooHighException(std::string const& msg)
	: mMessage("Form::GradeTooHighException: " + msg)
{
	// nothing to do
}

Form::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	Form::GradeTooHighException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char* Form::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*              GradeTooLowException : Constructor & Destructor               */
/* ************************************************************************** */
Form::GradeTooLowException::GradeTooLowException()
	: mMessage("Form::GradeTooLowException")
{
	// nothing to do
}

Form::GradeTooLowException::GradeTooLowException(std::string const& msg)
	: mMessage("Form::GradeTooLowException: " + msg)
{
	// nothing to do
}

Form::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	Form::GradeTooLowException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	Form::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& os, Form const& target)
{
	std::string	isFormSigned = target.getIsSigned() ? "true" : "false";

	os << target.getName()
	<< ", form signed " << isFormSigned
	<< ", form sign grade " << target.getSignGrade()
	<< ", form execution grade " << target.getExecuteGrade()
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
