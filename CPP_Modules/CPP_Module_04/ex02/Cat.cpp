/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:05:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 21:21:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Cat::Cat(void) : memory(0)
{
	std::cout << "[Cat] : Default constructor called" << std::endl;
	Animal::type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "[Cat] : Destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(std::string name) : name(name), memory(0)
{
	std::cout << "[Cat] : Parameterize constructor called" << std::endl;
	Animal::type = "Cat";
	this->brain = new Brain();
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
		Animal::operator=(target);
		if (target.type == "Cat") {
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

std::string	Cat::getType(void) const
{
	return this->type;
}

std::string	Cat::getName(void) const
{
	return this->name;
}

std::size_t	Cat::getMemory(void) const
{
	return this->memory;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Cat::makeSound(void) const
{
	std::cout << "[" << getType() << "] : Don't bark." << std::endl;
}

void	Cat::thinking(std::size_t idx) const
{
	std::cout << "[Cat] : Thinking about '" << this->brain->getIdea(idx) << "'" << std::endl;
}

void	Cat::learning(std::string const& idea)
{
	std::cout << "[Cat] : Learning idea..." << std::endl;
	this->brain->setIdea(this->memory, idea);
	this->memory++;
	if (this->memory >= 100)
		this->memory = this->memory % 100;
}
