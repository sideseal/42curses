/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:06:20 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 21:53:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

WrongCat::WrongCat(void)
{
	WrongAnimal::type = "WrongCat";
	std::cout << "[WrongCat] : Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : name(name)
{
	WrongAnimal::type = "WrongCat";
	std::cout << "[WrongCat] : Parameterize constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat] : Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& target) : WrongAnimal(target)
{
	std::cout << "[WrongCat] : Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

WrongCat&	WrongCat::operator=(WrongCat const& target)
{
	std::cout << "[WrongCat] : Copy assignment operator called" << std::endl;
	if (this != &target) {
		this->name = target.name;
		WrongAnimal::operator=(target);
	}
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	WrongCat::getType(void) const
{
	return this->type;
}

std::string	WrongCat::getName(void) const
{
	return this->name;
}

/******************************
 *   Public Member function   *
 ******************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "[" << getType() << "] : Don't bark." << std::endl;
}
