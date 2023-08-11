/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:00:53 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 00:08:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/*
 * Constructor & Destructor
 */

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	const_cast<std::string&>(ClapTrap::_name) = "_clap_name";
	_hit = 100;
	_energy = 50;
	_attack = 30;
	introduce();
}

DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name)
{
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	const_cast<std::string&>(_name) = name;
	const_cast<std::string&>(ClapTrap::_name) = const_cast<std::string&>(name) + "_clap_name";
	_hit = 100;
	_energy = 50;
	_attack = 30;
	introduce();
}

DiamondTrap::DiamondTrap(DiamondTrap const& target) : ClapTrap(target._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
	introduce();
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& target)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &target)
	{
		const_cast<std::string&>(_name) = target._name;
		_hit = target._hit;
		_energy = target._energy;
		_attack = target._attack;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (_name);
}

/*
 * Public Member Functions : DiamondTrap Actions
 */

void	DiamondTrap::introduce(void)
{
	std::cout << "["<< _name << "]: " << "kill... me..." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[" << _name << "]: " << "I... was called... DiamondTrap '" << _name << "'... but also... I was... ClapTrap '" << ClapTrap::_name << "'... The Cursed..." << std::endl;
}
