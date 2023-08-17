/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:54:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 03:54:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

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
			else
				this->inventory[i] = 0;
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
	for (std::size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "[" << this->getName() << "] : Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "[Character] : Invalid index" << std::endl;
		return ;
	}
	this->inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "[Character] : Invalid index" << std::endl;
		return ;
	}
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}

void	Character::showInventory(void)
{
	std::cout << "[INFO] : " << this->getName() << "'s Inventory : " << std::endl;
	for (std::size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			std::cout << "[" << i << "] : " << this->inventory[i]->getType() << std::endl;
		else
			std::cout << "[" << i << "] : " << "(empty)" << std::endl;
	}
	std::cout << std::endl;
}
