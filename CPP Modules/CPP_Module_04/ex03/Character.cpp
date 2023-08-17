/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:54:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 23:30:26 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/******************************
 * Constructor and Destructor *
 ******************************/

Character::Character(void)
{
	for (std::size_t i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::~Character(void)
{
	for (std::size_t i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character::Character(std::string const& name) : name(name)
{
	for (std::size_t i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(Character const& target)
{
	if (this != &target)
		*this = target;
}

Character&	Character::operator=(Character const& target)
{
	if (this != &target)
	{
		this->name = target.name;
		for (std::size_t i = 0; i < 4; i++) {
			delete this->inventory[i];
			if (target.inventory[i])
				this->inventory[i] = target.inventory[i]->clone();
		}
	}
	return *this;
}

/******************************
 *      Getter  function      *
 ******************************/

std::string const&	Character::getName(void) const
{
	return this->name;
}

/******************************
 *   Public Member function   *
 ******************************/

void	Character::equip(AMateria* m)
{
	(void)(m);
}

void	Character::unequip(int idx)
{
	(void)(idx);
}

void	Character::use(int idx, ICharacter& target)
{
	(void)(idx);
	(void)(target);
}
