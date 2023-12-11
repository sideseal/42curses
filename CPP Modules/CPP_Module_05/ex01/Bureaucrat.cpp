/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:36:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/29 22:27:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	_copyConstWarning(std::string const& object);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
Bureaucrat::Bureaucrat()
	: mName(std::string())
	, mGrade(0)
{
	// nothing to do
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	: mName(name),
	  mGrade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		// nothing to do
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& target)
	: mName(target.getName()),
	  mGrade(target.getGrade())
{
	// nothing to do
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& target)
{
	if (this != &target)
	{
		_copyConstWarning("mName");
		this->mGrade = target.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	// nothing to do
}

/* ************************************************************************** */
/*                         Getter & Setter Functions                          */
/* ************************************************************************** */
std::string const&	Bureaucrat::getName() const
{
	return this->mName;
}

int	Bureaucrat::getGrade() const
{
	return this->mGrade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException("Grade too high");
	}
	else if (grade > 150)
	{
		throw GradeTooLowException("Grade too low!");
	}
	else
	{
		this->mGrade = grade;
	}
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */
void	Bureaucrat::increaseGrade()
{
	int	grade = this->getGrade();

	if (grade > 1)
	{
		this->setGrade(--grade);
	}
	else
	{
		throw GradeTooHighException("Grade too high!");
	}
}

void	Bureaucrat::decreaseGrade()
{
	int	grade = this->getGrade();

	if (grade < 150)
	{
		this->setGrade(++grade);
	}
	else
	{
		throw GradeTooLowException("Grade too low!");
	}
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout
		<< this->getName()
		<< " signed "
		<< form.getName()
		<< std::endl;
	}
	catch (std::exception & e)
	{
		std::cout
		<< this->getName()
		<< " couldn't sign "
		<< form.getName()
		<< " because "
		<< e.what()
		<< std::endl;
	}
}

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
Bureaucrat::GradeTooHighException::GradeTooHighException()
	: mMessage("Bureaucrat::GradeTooHighException")
{
	// nothing to do
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const& msg)
	: mMessage("Bureaucrat::GradeTooHighException: " + msg)
{
	// nothing to do
}

Bureaucrat::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	Bureaucrat::GradeTooHighException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*              GradeTooLowException : Constructor & Destructor               */
/* ************************************************************************** */
Bureaucrat::GradeTooLowException::GradeTooLowException()
	: mMessage("Bureaucrat::GradeTooLowException")
{
	// nothing to do
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const& msg)
	: mMessage("Bureaucrat::GradeTooLowException: " + msg)
{
	// nothing to do
}

Bureaucrat::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	Bureaucrat::GradeTooLowException::getMessage() const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& os, Bureaucrat const& target)
{
	os << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
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
