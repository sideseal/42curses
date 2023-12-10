/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:09:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/10 18:52:33 by gychoi           ###   ########.fr       */
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
		std::ofstream	outfile(this->getName() + "_shrubbery");

		if (!outfile.is_open())
		{
			throw std::runtime_error("Unable to create file!");
		}

		// 한줄로 만들어서 파일 저장 후 에러 goodbit 체크
		srand(time(NULL));

		if (rand() % 2 == 1)
		{
			outfile << "                               " << "\n";
			outfile << "        .:-:: .- -.-           " << "\n";
			outfile << "       -===**++++== :-==       " << "\n";
			outfile << "     -=-::++=+--*+==+==-:      " << "\n";
			outfile << "   .=++=--=+*+#=+#**=:=*+=.    " << "\n";
			outfile << "   +#+=*=++*=+**#*+*##=*-=*.   " << "\n";
			outfile << "  .++-+=*####+=**#==#:###++.   " << "\n";
			outfile << "    *++=++%+#*+#*++==+**#-*+   " << "\n";
			outfile << "   :%%=+*+#*.**++*#+==+*+**+*. " << "\n";
			outfile << "  .+++-++#%###+-+****+=#++++=: " << "\n";
			outfile << " :**=###%%##%%***#**###*#*+.-: " << "\n";
			outfile << "  -*%*%******-=#=#####.-#%***  " << "\n";
			outfile << " .+#%#*##*#*%*%*##+**#**#.     " << "\n";
			outfile << "     *%%***#%%%#:*+##-*:=      " << "\n";
			outfile << "    =-+* *%  .-#:*#*##*#:      " << "\n";
			outfile << "               #%  #+          " << "\n";
			outfile << "               *#              " << "\n";
			outfile << "               *+              " << "\n";
			outfile << "               =:              " << "\n";
			outfile << "             .++%-=.           " << "\n";
			outfile << "                               " << "\n";
		}
		else
		{
			outfile << "                                   " << "\n";
			outfile << "                  __ _             " << "\n";
			outfile << "               !0@@@0NL            " << "\n";
			outfile << "       ;@NN|@b0@@0BN]@$@$H         " << "\n";
			outfile << "     ,;BNW@@0NNN@$@NN@0B@@b@L      " << "\n";
			outfile << "    PTEX]@BB^}@B0BN_/]y@$KQ@bP+    " << "\n";
			outfile << "    !@`]@W8@@@0@$#N@@NE]h]BBb`^    " << "\n";
			outfile << "    ` `P''$@@@BRB#B@NEp@p@WB/`     " << "\n";
			outfile << "        ,ARB@BBBNN@B@@@]RBNE`      " << "\n";
			outfile << "        0@@R@@@BK0B@B0B0NNB=_#_    " << "\n";
			outfile << "        0Z$BNBBB$BBBWBR2BN@@E&L_   " << "\n";
			outfile << "         B9@RBRRDBBR00BMH   F      " << "\n";
			outfile << "        TBR' 9R@B@NMB6N@H          " << "\n";
			outfile << "               TTB   T`0,          " << "\n";
			outfile << "                 N                 " << "\n";
			outfile << "                 L                 " << "\n";
			outfile << "                 :                 " << "\n";
			outfile << "                 L                 " << "\n";
			outfile << "                 L                 " << "\n";
			outfile << "                 I                 " << "\n";
			outfile << "                 h_                " << "\n";
			outfile << "                 '`                " << "\n";
			outfile << "                                   " << "\n";
		}

		outfile << "Created by " << executor.getName()
				<< "[" << executor.getGrade() << "]" << std::endl;

		outfile.close();

		throw "Successfully created shrubbery!";
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
