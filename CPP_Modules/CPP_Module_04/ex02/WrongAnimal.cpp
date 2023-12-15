/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 21:52:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "[WrongAnimal] : Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] : Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& target)
{
	std::cout << "[WrongAnimal] : Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& target)
{
	std::cout << "[WrongAnimal] : Copy assignment operator called" << std::endl;
	if (this != &target)
		this->type = target.type;
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}

/******************************
 *   Public Member function   *
 ******************************/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[" << getType() << "] : **Incomprehensible roars of countless WRONG animals**" << std::endl;
}
