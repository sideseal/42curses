/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:59:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/09 16:47:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*
 * Constructor & Destructor
 */

ClapTrap::ClapTrap(void) : _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name) : _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
	const_cast<std::string&>(_name) = name;
}

ClapTrap::ClapTrap(ClapTrap const& target)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	if (this != &target)
		*this = target;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& target)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap Destructor called" << std::endl;
}

/*
 * Public Member Functions : Getter
 */

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHit(void) const
{
	return (_hit);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (_energy);
}

unsigned int	ClapTrap::getAttack(void) const
{
	return (_attack);
}

/*
 * Public Member Functions : ClapTrap Actions
 */

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
		long long	hitTmp = static_cast<long long>(_hit);

		hitTmp -= amount;
		if (hitTmp <= 0)
		{
			_hit = 0;
			if (_energy > 0)
			{
				std::cout << "ClapTrap " << _name << " has been destroyed. All energy is drained" << std::endl;
				_energy = 0;
			}
			return ;
		}
		_hit -= amount;
	}
	else
		std::cout << "ClapTrap " << _name << "is already destroyed" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points of health" << std::endl;
		long long	hitTmp = static_cast<long long>(_hit);

		hitTmp += amount;
		if (hitTmp > std::numeric_limits<int>::max())
			_hit = std::numeric_limits<int>::max();
		else
			_hit += amount;
		_energy--;
	}
	else
		std::cout << "ClapTrap " << _name << " is out of energy. Cannot move!" << std::endl;
}
