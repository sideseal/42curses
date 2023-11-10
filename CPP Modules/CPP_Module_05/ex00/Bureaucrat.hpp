/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:13:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/10 22:56:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, short grade);
	Bureaucrat(Bureaucrat const& target);
	Bureaucrat&			operator=(Bureaucrat const& target);
	~Bureaucrat(void);

public:
	std::string const&	getName(void) const;
	short				getGrade(void) const;
	void				setGrade(short& grade);

public:
	// decrement
	// increment
	// exception

private:
	std::string const	mName;
	short				mGrade;
};

std::ostream&			operator<<(std::ostream& os, Bureaucrat const& target);

#endif /* __BUREAUCRAT_HPP__ */
