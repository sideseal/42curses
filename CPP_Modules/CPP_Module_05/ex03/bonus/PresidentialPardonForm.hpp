/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:31:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/11 18:25:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

/* ************************************************************************** */
/*                           PresidentialPardonForm                           */
/* ************************************************************************** */
class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const& targetsName);
	PresidentialPardonForm(PresidentialPardonForm const& target);
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& target);
	virtual ~PresidentialPardonForm();

public:
	virtual void			beSigned(Bureaucrat const& bureaucrat);
	virtual void			execute(Bureaucrat const& executor) const;

/* ************************************************************************** */
/*               PresidentialPardonForm::GradeTooHighException                */
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
/*                PresidentialPardonForm::GradeTooLowException                */
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
/*               PresidentialPardonForm::FormNotSignedException               */
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

std::ostream&	operator<<(std::ostream& os,
						   PresidentialPardonForm const& target);

#endif /* __PRESIDENTIALPARDONFORM_HPP__ */
