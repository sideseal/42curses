/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 03:05:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/18 03:47:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Base::~Base()
{
	// nothing to do
}

/* ************************************************************************** */
/*                             Exported Functions                             */
/* ************************************************************************** */

Base*	generate()
{
	srand(time(0));

	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			;
			// unreachable
	}
	return 0;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A*" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B*" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C*" << std::endl;
	}
	else
	{
		throw std::runtime_error("Bad Pointer");
	}
}

void	identify(Base& p)
{
	bool	flag = false;

	try
	{
		A&	a __attribute__((unused)) = dynamic_cast<A&>(p);
		std::cout << "A&" << std::endl;
		flag = true;
	}
	catch (...)
	{
		// nothing to do
	}
	try
	{
		B&	b __attribute__((unused)) = dynamic_cast<B&>(p);
		std::cout << "B&" << std::endl;
		flag = true;
	}
	catch (...)
	{
		// nothing to do
	}
	try
	{
		C&	c __attribute__((unused)) = dynamic_cast<C&>(p);
		std::cout << "C&" << std::endl;
		flag = true;
	}
	catch (...)
	{
		// nothing to do
	}

	if (flag == false)
	{
		throw std::bad_cast();
	}
	else
	{
		// identify success
	}
}
