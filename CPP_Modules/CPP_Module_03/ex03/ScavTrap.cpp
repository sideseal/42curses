/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:54:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 20:33:36 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/*
 * Constructor & Destructor
 */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	introduce();
}

ScavTrap::ScavTrap(std::string const& _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	const_cast<std::string&>(name) = _name;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	introduce();
}

ScavTrap::ScavTrap(ScavTrap const& target) : ClapTrap(target.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
	introduce();
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& target)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &target)
	{
		const_cast<std::string&>(name) = target.name;
		_hit = target._hit;
		_energy = target._energy;
		_attack = target._attack;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

/*
 * Public Member Functions : ScavTrap Actions
 */

void	ScavTrap::attack(std::string const& target)
{
	if (_energy > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << _attack << " points of damage!" << std::endl;
		_energy--;
	}
	else
		std::cout << "ScavTrap " << getName() << " is out of energy. Cannot move!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_energy > 0)
	{
		std::cout << "ScavTrap " << getName() << " is guarding the gate" << std::endl;
		std::cout << "[" << getName() << "]: " << "Guarding gates is FUN!" << std::endl;
		_energy--;
	}
	else
		std::cout << "ScavTrap " << getName() << " is out of energy. Cannot move!" << std::endl;
}

void	ScavTrap::introduce(void)
{
	std::cout << "["<< getName() << "]: " << "Halt, moon citizen! I've been chosen to stand out here far, far away from everyone else -- to guard the main gate to the old communications facility." << std::endl;
}
