/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:01:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/11 18:27:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

/* ************************************************************************** */
/*                            RobotomyRequestForm                             */
/* ************************************************************************** */
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& targetName);
	RobotomyRequestForm(RobotomyRequestForm const& target);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& target);
	virtual ~RobotomyRequestForm();

public:
	virtual void			beSigned(Bureaucrat const& bureaucrat);
	virtual void			execute(Bureaucrat const& executor) const;

/* ************************************************************************** */
/*                 RobotomyRequestForm::GradeTooHighException                 */
/* ************************************************************************** */
public:
	class GradeTooHighException : public AForm::GradeTooHighException
	{
	public:
		GradeTooHighException();
		GradeTooHighException(std::string const& msg);
		GradeTooHighException(GradeTooHighException const& target);
		GradeTooHighException&	operator=(GradeTooHighException const& target);
		virtual ~GradeTooHighException() throw();

	public:
		std::string const&		getMessage() const;

	public:
		virtual char const*		what() const throw();

	private:
		std::string				mMessage;
	};

/* ************************************************************************** */
/*                 RobotomyRequestForm::GradeTooLowException                  */
/* ************************************************************************** */
public:
	class GradeTooLowException : public AForm::GradeTooLowException
	{
	public:
		GradeTooLowException();
		GradeTooLowException(std::string const& msg);
		GradeTooLowException(GradeTooLowException const& target);
		GradeTooLowException&	operator=(GradeTooLowException const& target);
		virtual ~GradeTooLowException() throw();

	public:
		std::string const&		getMessage() const;

	public:
		virtual char const*		what() const throw();

	private:
		std::string				mMessage;
	};

/* ************************************************************************** */
/*                RobotomyRequestForm::FormNotSignedException                 */
/* ************************************************************************** */
public:
	class FormNotSignedException : public std::exception
	{
	public:
		FormNotSignedException();
		FormNotSignedException(std::string const& msg);
		FormNotSignedException(FormNotSignedException const& target);
		FormNotSignedException&	operator=(FormNotSignedException const& target);
		virtual ~FormNotSignedException() throw();

	public:
		std::string const&		getMessage() const;

	public:
		virtual char const*		what() const throw();

	private:
		std::string				mMessage;
	};
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const& target);

#endif /* __ROBOTOMYREQUESTFORM_HPP__ */
