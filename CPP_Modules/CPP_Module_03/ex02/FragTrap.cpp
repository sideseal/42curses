/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:20:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 23:53:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/*
 * Constructor & Destructor
 */

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
	introduce();
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	const_cast<std::string&>(_name) = name;
	_hit = 100;
	_energy = 100;
	_attack = 30;
	introduce();
}

FragTrap::FragTrap(FragTrap const& target) : ClapTrap(target.getName())
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
	introduce();
}

FragTrap&	FragTrap::operator=(FragTrap const& target)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &target)
	{
		const_cast<std::string&>(_name) = target._name;
		_hit = target._hit;
		_energy = target._energy;
		_attack = target._attack;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

/*
 * Public Member Functions : FragTrap Actions
 */

void	FragTrap::introduce(void)
{
	std::cout << "["<< getName() << "]: " << "Give me fives!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_energy > 0)
	{
		std::cout << "FragTrap " << _name << " raises his hand" << std::endl;
		std::cout << "[" << getName() << "]: " << "HIGH FIVES GUYS!" << std::endl;
		_energy--;
	}
	else
		std::cout << "FragTrap " << _name << " is out of energy. Cannot move!" << std::endl;
}
