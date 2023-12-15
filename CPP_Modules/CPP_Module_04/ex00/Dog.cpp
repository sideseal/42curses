/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:57 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 22:20:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Dog::Dog(void)
{
	Animal::type = "Dog";
	std::cout << "[Dog] : Default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog] : Destructor called" << std::endl;
}

Dog::Dog(std::string name) : name(name)
{
	Animal::type = "Dog";
	std::cout << "[Dog] : Parameterize constructor called" << std::endl;
}

Dog::Dog(Dog const& target) : Animal(target)
{
	std::cout << "[Dog] : Copy constructor called" << std::endl;
	if (this != &target) {
		*this = target;
		Animal::type = "Dog";
	}
}

Dog&	Dog::operator=(Dog const& target)
{
	std::cout << "[Dog] : Copy assignment operator called" << std::endl;
	if (this != &target) {
		this->name = target.name;
		Animal::operator=(target);
	}
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	Dog::getType(void) const
{
	return this->type;
}

std::string	Dog::getName(void) const
{
	return this->name;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Dog::makeSound(void) const
{
	std::cout << "[" << getType() << "] : Bark!" << std::endl;
}
