/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:01:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/11 22:59:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

static void	_copyConstWarning(std::string const& variable);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm(std::string(), 72, 45)
{
	// nothing to do
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& targetName)
	: AForm(targetName, 72, 45)
{
	// nothing to do
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& target) try
	: AForm(target.getName(), target.getSignGrade(), target.getExecuteGrade())
{
	// nothing to do
}
catch (std::exception & e)
{
	throw;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=
(RobotomyRequestForm const& target)
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

RobotomyRequestForm::~RobotomyRequestForm()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */
void	RobotomyRequestForm::beSigned(Bureaucrat const& bureaucrat)
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
		std::cout
		<< "\033[4m"
		<< "[Unbearably loud drilling noise]"
		<< "\033[0m"
		<< std::endl;

		srand(time(NULL));

		if (rand() % 2 == 1)
		{
			std::cout
			<< "INFO: Successfully robotomized "
			<< this->getName()
			<< "." << std::endl;
		}
		else
		{
			std::cout
			<< "INFO: Robotomize "
			<< this->getName()
			<< " Failed." << std::endl;
		}
	}
}

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
RobotomyRequestForm::GradeTooHighException::GradeTooHighException()
	: mMessage("RobotomyRequestForm::GradeTooHighException")
{
	// nothing to do
}

RobotomyRequestForm::GradeTooHighException::GradeTooHighException
(std::string const& msg)
	: mMessage("RobotomyRequestForm::GradeTooHighException: " + msg)
{
	// nothing to do
}

RobotomyRequestForm::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: AForm::GradeTooHighException(target.getMessage())
{
	// nothing to do
}

RobotomyRequestForm::GradeTooHighException&
RobotomyRequestForm::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

RobotomyRequestForm::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	RobotomyRequestForm::GradeTooHighException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char*	RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*              GradeTooLowException : Constructor & Destructor               */
/* ************************************************************************** */
RobotomyRequestForm::GradeTooLowException::GradeTooLowException()
	: mMessage("RobotomyRequestForm::GradeTooLowException")
{
	// nothing to do
}

RobotomyRequestForm::GradeTooLowException::GradeTooLowException
(std::string const& msg)
	: mMessage("RobotomyRequestForm::GradeTooLowException: " + msg)
{
	// nothing to do
}

RobotomyRequestForm::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: AForm::GradeTooLowException(target.getMessage())
{
	// nothing to do
}

RobotomyRequestForm::GradeTooLowException&
RobotomyRequestForm::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

RobotomyRequestForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	RobotomyRequestForm::GradeTooLowException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*             FormNotSignedException : Constructor & Destructor              */
/* ************************************************************************** */
RobotomyRequestForm::FormNotSignedException::FormNotSignedException()
	: mMessage("RobotomyRequestForm::FormNotSignedException")
{
	// nothing to do
}

RobotomyRequestForm::FormNotSignedException::FormNotSignedException
(std::string const& msg)
	: mMessage("RobotomyRequestForm::FormNotSignedException: " + msg)
{
	// nothing to do
}

RobotomyRequestForm::FormNotSignedException::FormNotSignedException
(FormNotSignedException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

RobotomyRequestForm::FormNotSignedException&
RobotomyRequestForm::FormNotSignedException::operator=
(FormNotSignedException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

RobotomyRequestForm::FormNotSignedException::~FormNotSignedException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  FormNotSigendException : Getter Function                  */
/* ************************************************************************** */
std::string const&	RobotomyRequestForm::FormNotSignedException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 FormNotSigendException : Function Override                 */
/* ************************************************************************** */
const char*	RobotomyRequestForm::FormNotSignedException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */

std::ostream&	operator<<
(std::ostream& os, RobotomyRequestForm const& target)
{
	std::string	isAFormSigned = target.getIsSigned() ? "true" : "false";

	os << target.getName()
	<< ", RobotomyRequestForm signed " << isAFormSigned
	<< ", RobotomyRequestForm sign grade " << target.getSignGrade()
	<< ", RobotomyRequestForm execution grade " << target.getExecuteGrade()
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
