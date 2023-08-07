/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:59:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/07 21:53:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _hit(10), _energy(10), _attack(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name) : _hit(10), _energy(10), _attack(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
	const_cast<std::string&>(_name) = name;
}

ClapTrap::ClapTrap(ClapTrap const& target)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& target)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &target)
	{
		const_cast<std::string&>(_name) = target._name;
		_hit = target._hit;
		_energy = target._energy;
		_attack = target._attack;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const& target)
{
	if (_energy > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack << " points of damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "ClapTrap " << _name << " is out of energy. Cannot move!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
	if (_hit > 0)
	{
		_hit -= amount;
		if (_hit <= 0)
		{
			_hit = 0;
			if (_energy > 0)
			{
				std::cout << "ClapTrap " << _name << " has been destroyed. All energy is drained" << std::endl;
				_energy = 0;
			}
		}
	}
	if (_energy == 0)
		std::cout << "ClapTrap " << _name << " is out of energy. Cannot move!" << std::endl;
	std::cout << "* ClapTrap " << _name <<"'s points of health is " << _hit << " *" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points of health" << std::endl;
		_hit += amount;
		std::cout << "* ClapTrap " << _name <<"'s points of health is " << _hit << " *" << std::endl;
		_energy--;
	}
	else
		std::cout << "ClapTrap " << _name << " is out of energy. Cannot move!" << std::endl;
}
