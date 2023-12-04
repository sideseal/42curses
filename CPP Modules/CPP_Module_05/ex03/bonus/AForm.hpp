/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:46:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/03 20:31:22 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                   AForm                                    */
/* ************************************************************************** */
class AForm
{
public:
	AForm();
	AForm(std::string const& name, int signGrade, int executeGrade)
		throw(GradeTooHighException, GradeTooLowException);
	AForm(AForm const& target);
	AForm&				operator=(AForm const& target);
	virtual ~AForm();

public:
	std::string const&	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	void				setIsSigned(bool isSigned);

public:
	virtual void		beSigned(Bureaucrat const& bureaucrat) = 0;
	virtual void		execute(Bureaucrat const& executor) const = 0;

private:
	std::string const	mName;
	bool				mbIsSigned;
	int const			mSignGrade;
	int const			mExecuteGrade;

/* ************************************************************************** */
/*                        AForm::GradeTooHighException                        */
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
/*                         AForm::GradeTooLowException                        */
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

std::ostream&			operator<<(std::ostream& os, AForm const& target);

#endif /* __AFORM_HPP__ */
