/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:36:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/10 22:42:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	_constCopyWarning(std::string const& object);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void)
	: mName(std::string())
	, mGrade(0)
{
	// nothing to do
}

Bureaucrat::Bureaucrat(std::string name, short grade)
	: mName(name)
{
	// if grade is in range
	this->mGrade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& target)
	: mName(target.getName())
	, mGrade(target.getGrade())
{
	// nothing to do
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& target)
{
	if (this != &target)
	{
		_constCopyWarning(this->getName());
		this->mGrade = target.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	// nothing to do
}

/* ************************************************************************** */
/*                              Getter & Setter                               */
/* ************************************************************************** */

std::string const&	Bureaucrat::getName(void) const
{
	return this->mName;
}

short	Bureaucrat::getGrade(void) const
{
	return this->mGrade;
}

void	Bureaucrat::setGrade(short& grade)
{
	this->mGrade = grade;
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

static void	_constCopyWarning(std::string const& object)
{
	std::cout << "INFO: You are trying to overwrite a const type variable: " <<
		object << ". " << "This operation will be ignored." << std::endl;
}
