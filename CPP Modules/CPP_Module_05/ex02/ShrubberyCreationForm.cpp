/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:09:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/11 22:20:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static void	_copyConstWarning(std::string const& variable);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(std::string(), 145, 137)
{
	// nothing to do
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& targetName)
	: AForm(targetName, 145, 137)
{
	// nothing to do
}

ShrubberyCreationForm::ShrubberyCreationForm
(ShrubberyCreationForm const& target)
	throw(GradeTooHighException, GradeTooLowException) try
	: AForm(target.getName(), target.getSignGrade(), target.getExecuteGrade())
{
	// nothing to do
}
catch (std::exception & e)
{
	throw;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=
(ShrubberyCreationForm const& target)
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */
void	ShrubberyCreationForm::beSigned(Bureaucrat const& bureaucrat)
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
throw(GradeTooLowException, FormNotSignedException)
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
		std::ofstream	outfile((this->getName() + "_shrubbery").c_str());

		if (!outfile.is_open())
		{
			throw std::runtime_error("Unable to create file!");
		}

		char const* tree =
			"                               \n"
			"        .:-:: .- -.-           \n"
			"       -===**++++== :-==       \n"
			"     -=-::++=+--*+==+==-:      \n"
			"   .=++=--=+*+#=+#**=:=*+=.    \n"
			"   +#+=*=++*=+**#*+*##=*-=*.   \n"
			"  .++-+=*####+=**#==#:###++.   \n"
			"    *++=++%+#*+#*++==+**#-*+   \n"
			"   :%%=+*+#*.**++*#+==+*+**+*. \n"
			"  .+++-++#%###+-+****+=#++++=: \n"
			" :**=###%%##%%***#**###*#*+.-: \n"
			"  -*%*%******-=#=#####.-#%***  \n"
			" .+#%#*##*#*%*%*##+**#**#.     \n"
			"     *%%***#%%%#:*+##-*:=      \n"
			"    =-+* *%  .-#:*#*##*#:      \n"
			"               #%  #+          \n"
			"               *#              \n"
			"               *+              \n"
			"               =:              \n"
			"             .++%-=.           \n"
			"                               \n"
			"Created by ";

		outfile << tree
				<< executor.getName()
				<< "[" << executor.getGrade() << "]"
				<< std::endl;

		if (!outfile.good())
		{
			throw std::runtime_error("Error writing to file!");
		}

		outfile.close();

		if (outfile.fail())
		{
			throw std::runtime_error("Error closing file!");
		}

		std::cout << "INFO: Successfully created shrubbery!" << std::endl;
	}
}

/* ************************************************************************** */
/*              GradeTooHighException : Constructor & Destructor              */
/* ************************************************************************** */
ShrubberyCreationForm::GradeTooHighException::GradeTooHighException()
	: mMessage("ShrubberyCreationForm::GradeTooHighException")
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException
(std::string const& msg)
	: mMessage("ShrubberyCreationForm::GradeTooHighException: " + msg)
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooHighException&
ShrubberyCreationForm::GradeTooHighException::operator=
(GradeTooHighException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

ShrubberyCreationForm::GradeTooHighException::~GradeTooHighException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  GradeTooHighException : Getter Function                   */
/* ************************************************************************** */
std::string const&	ShrubberyCreationForm::GradeTooHighException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 GradeTooHighException : Function Override                  */
/* ************************************************************************** */
const char*	ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*              GradeTooLowException : Constructor & Destructor               */
/* ************************************************************************** */
ShrubberyCreationForm::GradeTooLowException::GradeTooLowException()
	: mMessage("ShrubberyCreationForm::GradeTooLowException")
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException
(std::string const& msg)
	: mMessage("ShrubberyCreationForm::GradeTooLowException: " + msg)
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

ShrubberyCreationForm::GradeTooLowException&
ShrubberyCreationForm::GradeTooLowException::operator=
(GradeTooLowException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

ShrubberyCreationForm::GradeTooLowException::~GradeTooLowException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                   GradeTooLowException : Getter Function                   */
/* ************************************************************************** */
std::string const&	ShrubberyCreationForm::GradeTooLowException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                  GradeTooLowException : Function Override                  */
/* ************************************************************************** */
const char*	ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*             FormNotSignedException : Constructor & Destructor              */
/* ************************************************************************** */
ShrubberyCreationForm::FormNotSignedException::FormNotSignedException()
	: mMessage("ShrubberyCreationForm::FormNotSignedException")
{
	// nothing to do
}

ShrubberyCreationForm::FormNotSignedException::FormNotSignedException
(std::string const& msg)
	: mMessage("ShrubberyCreationForm::FormNotSignedException: " + msg)
{
	// nothing to do
}

ShrubberyCreationForm::FormNotSignedException::FormNotSignedException
(FormNotSignedException const& target)
	: mMessage(target.getMessage())
{
	// nothing to do
}

ShrubberyCreationForm::FormNotSignedException&
ShrubberyCreationForm::FormNotSignedException::operator=
(FormNotSignedException const& target)
{
	if (this != &target)
	{
		this->mMessage = target.getMessage();
	}
	return *this;
}

ShrubberyCreationForm::FormNotSignedException::~FormNotSignedException() throw()
{
	// nothing to do
}

/* ************************************************************************** */
/*                  FormNotSigendException : Getter Function                  */
/* ************************************************************************** */
std::string const&	ShrubberyCreationForm::FormNotSignedException::getMessage()
	const
{
	return this->mMessage;
}

/* ************************************************************************** */
/*                 FormNotSigendException : Function Override                 */
/* ************************************************************************** */
const char*	ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
	return this->getMessage().c_str();
}

/* ************************************************************************** */
/*                              Global Function                               */
/* ************************************************************************** */

std::ostream&	operator<<
(std::ostream& os, ShrubberyCreationForm const& target)
{
	std::string	isAFormSigned = target.getIsSigned() ? "true" : "false";

	os << target.getName()
	<< ", ShrubberyCreationForm signed " << isAFormSigned
	<< ", ShrubberyCreationForm sign grade " << target.getSignGrade()
	<< ", ShrubberyCreationForm execution grade " << target.getExecuteGrade()
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
