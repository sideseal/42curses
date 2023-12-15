/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:35:24 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 00:51:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

Cure::Cure(void) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(Cure const& target) : AMateria("cure")
{
	if (this != &target)
		*this = target;
}

Cure&	Cure::operator=(Cure const& target)
{
	if (this != &target)
		AMateria::operator=(target);
	return *this;
}

/******************************
 *   Public Member function   *
 ******************************/

AMateria*	Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
