/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:34:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 21:09:50 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Brain::Brain(void)
{
	std::cout << "[Brain] : Default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] : Destructor called" << std::endl;
}

Brain::Brain(Brain const& target)
{
	std::cout << "[Brain] : Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

Brain&	Brain::operator=(Brain const& target)
{
	std::cout << "[Brain] : Copy assignment operatr called" << std::endl;
	if (this != &target)
		for (std::size_t i = 0; i < 100; i++)
			this->ideas[i] = target.ideas[i];
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string	Brain::getIdea(std::size_t idx)
{
	if (idx > 100) {
		std::cout << "[Brain] : Invalid ideas index" << std::endl;
		return std::string();
	}
	return this->ideas[idx];
}

void	Brain::setIdea(std::size_t idx, std::string const& idea)
{
	if (idx > 100) {
		std::cout << "[Brain] : Invalid ideas index" << std::endl;
		return ;
	}
	this->ideas[idx] = idea;
}
