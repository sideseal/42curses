/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:00:53 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 20:37:26 by gychoi           ###   ########.fr       */
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
	const_cast<std::string&>(ClapTrap::name) = "_clap_name";
	_hit = 100;
	_energy = 50;
	_attack = 30;
	introduce();
}

DiamondTrap::DiamondTrap(std::string const& _name) : ClapTrap(_name)
{
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	const_cast<std::string&>(name) = _name;
	const_cast<std::string&>(ClapTrap::name) = const_cast<std::string&>(_name) + "_clap_name";
	_hit = 100;
	_energy = 50;
	_attack = 30;
	introduce();
}

DiamondTrap::DiamondTrap(DiamondTrap const& target) : ClapTrap(target.name)
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
		const_cast<std::string&>(name) = target.name;
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

/*
 * Public Member Functions : Getter
 */

std::string	DiamondTrap::getName(void) const
{
	return (name);
}

/*
 * Public Member Functions : DiamondTrap Actions
 */

void	DiamondTrap::introduce(void)
{
	std::cout << "["<< name << "]: " << "kill... me..." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[" << name << "]: " << "I... was called... DiamondTrap '" << name << "'... but also... I was... ClapTrap '" << ClapTrap::name << "'... The Cursed..." << std::endl;
}
