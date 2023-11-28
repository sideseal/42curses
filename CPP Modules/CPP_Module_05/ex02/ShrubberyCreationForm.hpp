/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:10:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/28 22:47:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

/* ************************************************************************** */
/*                           ShrubberyCreationForm                            */
/* ************************************************************************** */
class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
		throw(GradeTooHighException, GradeTooLowException);
	ShrubberyCreationForm(ShrubberyCreationForm const& target);
	ShrubberyCreationForm	operator=(ShrubberyCreationForm const& target);
	virtual ~ShrubberyCreationForm();

public:
	virtual void			beSigned(Bureaucrat const& bureaucrat)
								throw(GradeTooLowException);

/* ************************************************************************** */
/*                ShrubberyCreationForm::GradeTooHighException                */
/* ************************************************************************** */
public:
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(std::string const& msg);
		GradeTooHighException(GradeTooHighException const& target);
		GradeTooHighException	operator=(GradeTooHighException const& target);
		virtual ~GradeTooHighException() throw();
	};

/* ************************************************************************** */
/*                ShrubberyCreationForm::GradeTooLowException                 */
/* ************************************************************************** */
public:
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(std::string const& msg);
		GradeTooLowException(GradeTooLowException const& target);
		GradeTooLowException	operator=(GradeTooLowException const& target);
		virtual ~GradeTooLowException() throw();
	};
};

#endif /* __SHRUBBERYCREATIONFORM_HPP__ */
