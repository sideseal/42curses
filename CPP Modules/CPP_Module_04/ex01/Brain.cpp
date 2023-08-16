/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:34:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 19:46:34 by gychoi           ###   ########.fr       */
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
	if (this != &target)
		*this = target;
	std::cout << "[Brain] : Copy constructor called" << std::endl;
}

Brain&	Brain::operator=(Brain const& target)
{
	if (this != &target)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = target.ideas[i];
	std::cout << "[Brain] : Copy assignment operatr called" << std::endl;
	return *this;
}
