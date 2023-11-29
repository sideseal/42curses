/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:10:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/29 22:39:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <fstream>

#include "AForm.hpp"

/* ************************************************************************** */
/*                           ShrubberyCreationForm                            */
/* ************************************************************************** */
class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& targetsName);
	ShrubberyCreationForm(ShrubberyCreationForm const& target)
		throw(GradeTooHighException, GradeTooLowException);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& target);
	virtual ~ShrubberyCreationForm();

public:
	virtual void			beSigned(Bureaucrat const& bureaucrat)
								throw(GradeTooLowException);
	virtual void			execute(Bureaucrat const& executor) const
								throw(std::runtime_error, GradeTooHighException,
									  GradeTooLowException);

/* ************************************************************************** */
/*                ShrubberyCreationForm::GradeTooHighException                */
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
/*                ShrubberyCreationForm::GradeTooLowException                 */
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
};

std::ostream&			operator<<(std::ostream& os,
								   ShrubberyCreationForm const& target);

#endif /* __SHRUBBERYCREATIONFORM_HPP__ */
