/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:53:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/18 03:06:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif /* __BASE_HPP__ */
