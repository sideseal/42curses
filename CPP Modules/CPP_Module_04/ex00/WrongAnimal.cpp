/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/15 20:38:41 by gychoi           ###   ########.fr       */
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
	if (this != &target)
		*this = target;
	std::cout << "[WrongAnimal] : Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& target)
{
	if (this != &target)
		this->type = target.type;
	std::cout << "[WrongAnimal] : Copy assignment operator called" << std::endl;
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
