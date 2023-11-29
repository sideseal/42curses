/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:13:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/29 22:28:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <stdexcept>
#include <string>

class Form;

/* ************************************************************************** */
/*                                 Bureaucrat                                 */
/* ************************************************************************** */
class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string const& name, int grade)
		throw(GradeTooHighException, GradeTooLowException);
	Bureaucrat(Bureaucrat const& target);
	Bureaucrat&			operator=(Bureaucrat const& target);
	~Bureaucrat();

public:
	std::string const&	getName() const;
	int					getGrade() const;
	void				setGrade(int grade)
							throw(GradeTooHighException, GradeTooLowException);

public:
	void				increaseGrade() throw(GradeTooHighException);
	void				decreaseGrade() throw(GradeTooLowException);
	void				signForm(Form& form);


private:
	std::string const	mName;
	int					mGrade;

/* ************************************************************************** */
/*                     Bureaucrat::GradeTooHighException                      */
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
/*                      Bureaucrat::GradeTooLowException                      */
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

std::ostream&			operator<<(std::ostream& os, Bureaucrat const& target);

#endif /* __BUREAUCRAT_HPP__ */
