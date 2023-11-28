/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:46:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/28 21:48:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

static void	_copyConstWarning(std::string const& object);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
AForm::AForm()
	: mName(std::string()),
	  mbIsSigned(false),
	  mSignGrade(0),
	  mExecuteGrade(0)
{
	// nothing to do
}

AForm::AForm(std::string const& name, int signGrade, int executeGrade)
	throw(GradeTooHighException, GradeTooLowException)
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

AForm::AForm(AForm const& target)
	: mName(target.getName()),
	  mbIsSigned(false),
	  mSignGrade(target.getSignGrade()),
	  mExecuteGrade(target.getExecuteGrade())
{
	// nothing to do
}

AForm&	AForm::operator=(AForm const& target)
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

AForm::~AForm()
{
	// nothing to do
}

/* ************************************************************************** */
/*                         Getter & Setter Functions                          */
/* ************************************************************************** */
std::string const&	AForm::getName() const
{
	return this->mName;
}

bool	AForm::getIsSigned() const
{
	return this->mbIsSigned;
}

int	AForm::getSignGrade() const
{
	return this->mSignGrade;
}

int	AForm::getExecuteGrade() const
{
	return this->mExecuteGrade;
}

void	AForm::setIsSigned(bool isSigned)
{
	this->mbIsSigned = isSigned;
}

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
AForm::GradeTooHighException::GradeTooHighException()
	: mMessage("AForm::GradeTooHighException")
{
	// nothing to do
}

AForm::GradeTooHighException::GradeTooHighException(std::string const& msg)
	: mMessage("AForm::GradeTooHighException: " + msg)
{
	// nothing to do
}

AForm::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

AForm::GradeTooHighException&
AForm::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	AForm::GradeTooHighException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char* AForm::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*             GradeTooLowException : Construccctor & Destructor              */
/* ************************************************************************** */
AForm::GradeTooLowException::GradeTooLowException()
	: mMessage("AForm::GradeTooLowException")
{
	// nothing to do
}

AForm::GradeTooLowException::GradeTooLowException(std::string const& msg)
	: mMessage("AForm::GradeTooLowException: " + msg)
{
	// nothing to do
}

AForm::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

AForm::GradeTooLowException&
AForm::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	AForm::GradeTooLowException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	AForm::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& os, AForm const& target)
{
	std::string	isAFormSigned = target.getIsSigned() ? "true" : "false";

	os << target.getName()
	<< ", AForm signed " << isAFormSigned
	<< ", AForm sign grade " << target.getSignGrade()
	<< ", AForm execution grade " << target.getExecuteGrade()
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
