/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:23:50 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/28 16:46:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                    Form                                    */
/* ************************************************************************** */
class Form
{
public:
	Form();
	Form(std::string const& name, int signGrade, int executeGrade);
	Form(Form const& target);
	Form&				operator=(Form const& target);
	~Form();

public:
	std::string const&	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	void				setIsSigned(bool isSigned);

public:
	void				beSigned(Bureaucrat const& bureaucrat);

private:
	std::string const	mName;
	bool				mbIsSigned;
	int const			mSignGrade;
	int const			mExecuteGrade;

/* ************************************************************************** */
/*                        Form::GradeTooHighException                         */
/* ************************************************************************** */
public:
	class GradeTooHighException : public std::exception
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
/*                         Form::GradeTooLowException                         */
/* ************************************************************************** */
public:
	class GradeTooLowException : public std::exception
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

std::ostream&			operator<<(std::ostream& os, Form const& target);

#endif /* __FORM_HPP__ */
