/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:57 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 18:20:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Dog::Dog(void) : memory(0)
{
	std::cout << "[Dog] : Default constructor called" << std::endl;
	Animal::type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "[Dog] : Destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(std::string name) : name(name), memory(0)
{
	std::cout << "[Dog] : Parameterize constructor called" << std::endl;
	Animal::type = "Dog";
	this->brain = new Brain();
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
		Animal::operator=(target);
		if (target.type == "Dog") {
			this->name = target.name;
			this->memory = target.memory;
			delete this->brain;
			this->brain = new Brain(*target.brain);
		}
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

std::size_t	Dog::getMemory(void) const
{
	return this->memory;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Dog::makeSound(void) const
{
	std::cout << "[" << getType() << "] : Bark!" << std::endl;
}

void	Dog::thinking(std::size_t idx) const
{
	std::cout << "[Dog] : Thinking about '" << this->brain->getIdea(idx) << "'" << std::endl;
}

void	Dog::learning(std::string const& idea)
{
	std::cout << "[Dog] : Learning idea..." << std::endl;
	this->brain->setIdea(this->memory, idea);
	this->memory++;
	if (this->memory >= 100)
		this->memory = this->memory % 100;
}
