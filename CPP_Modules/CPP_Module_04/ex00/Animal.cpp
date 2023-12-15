/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:02:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 21:52:22 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Animal::Animal(void) : type("Animal")
{
	std::cout << "[Animal] : Default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[Animal] : Destructor called" << std::endl;
}

Animal::Animal(Animal const& target)
{
	std::cout << "[Animal] : Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

Animal&	Animal::operator=(Animal const& target)
{
	std::cout << "[Animal] : Copy assignment operator called" << std::endl;
	if (this != &target)
		this->type = target.type;
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	Animal::getType(void) const
{
	return this->type;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Animal::makeSound(void) const
{
	std::cout << "[" << getType() << "] : **Incomprehensible roars of countless animals**" << std::endl;
}
