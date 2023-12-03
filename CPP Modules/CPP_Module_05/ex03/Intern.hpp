/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:22:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/04 01:32:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                                   Intern                                   */
/* ************************************************************************** */
class Intern
{
public:
	Intern();
	Intern(Intern const& target);
	Intern&	operator=(Intern const& target);
	~Intern();

public:
	enum eFormType
	{
		PRESIDENTIAL_PARDON,
		ROBOTOMY_REQUEST,
		SHRUBBERY_CREATION,
		FORM_SIZE
	};
	AForm*	makeForm(std::string const& formName,
					 std::string const& targetName);
};

#endif /* __INTERN_HPP__ */
