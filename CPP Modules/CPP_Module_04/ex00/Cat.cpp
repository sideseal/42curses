/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:05:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 22:31:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Cat::Cat(void)
{
	Animal::type = "Cat";
	std::cout << "[Cat] : Default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] : Destructor called" << std::endl;
}

Cat::Cat(std::string name) : name(name)
{
	Animal::type = "Cat";
	std::cout << "[Cat] : Parameterize constructor called" << std::endl;
}

Cat::Cat(Cat const& target) : Animal(target)
{
	std::cout << "[Cat] : Copy constructor called" << std::endl;
	if (this != &target) {
		*this = target;
		Animal::type = "Cat";
	}
}

Cat&	Cat::operator=(Cat const& target)
{
	std::cout << "[Cat] : Copy assignment operator called" << std::endl;
	if (this != &target) {
		this->name = target.name;
		Animal::operator=(target);
	}
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	Cat::getType(void) const
{
	return this->type;
}

std::string	Cat::getName(void) const
{
	return this->name;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Cat::makeSound(void) const
{
	std::cout << "[" << getType() << "] : Don't bark." << std::endl;
}
