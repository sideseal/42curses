/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:18:39 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 00:51:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(Ice const& target) : AMateria("ice")
{
	if (this != &target)
		*this = target;
}

Ice&	Ice::operator=(Ice const& target)
{
	if (this != &target)
		AMateria::operator=(target);
	return *this;
}

/******************************
 *   Public Member function   *
 ******************************/

AMateria*	Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
