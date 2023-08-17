/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:05:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 22:14:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/******************************
 * Constructor and Destructor *
 ******************************/

AMateria::AMateria(void) : type("AMateria") {}

AMateria::~AMateria(void) {}

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::AMateria(AMateria const& target)
{
	if (this != &target)
		*this = target;
}

AMateria&	AMateria::operator=(AMateria const& target)
{
	if (this != &target)
		(void)(target);
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string const&	AMateria::getType(void) const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	(void)(target);
	// ...
}
