/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:28 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 01:11:51 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

/******************************
 * Constructor and Destructor *
 ******************************/

MateriaSource::MateriaSource(void)
{
	for (std::size_t i = 0; i < 4; i++)
		this->list[i] = 0;
}

MateriaSource::~MateriaSource(void)
{
	for (std::size_t i = 0; i < 4; i++)
		delete this->list[i];
}

MateriaSource::MateriaSource(MateriaSource const& target)
{
	if (this != &target)
		*this = target;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& target)
{
	if (this != &target)
	{
		for (std::size_t i = 0; i < 4; i++)
		{
			delete this->list[i];
			if (target.list[i])
				this->list[i] = target.list[i]->clone();
		}
	}
	return *this;
}

/******************************
 *   Public Member function   *
 ******************************/

void	MateriaSource::learnMateria(AMateria* m)
{
	for (std::size_t i = 0; i < 4; i++)
	{
		if (!this->list[i])
		{
			this->list[i] = m;
			return ;
		}
	}
	delete m;
	std::cout << "[MateriaSource] : List is full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (std::size_t i = 0; i < 4; i++)
	{
		if (this->list[i] && this->list[i]->getType() == type)
			return this->list[i]->clone();
	}
	std::cout << "[MateriaSource] : Cannot find Materia : " << type << std::endl;
	return 0;
}

void	MateriaSource::showMateria(void)
{
	std::cout << "[INFO] : Learned Materia list : " << std::endl;
	for (std::size_t i = 0; i < 4; i++)
	{
		if (this->list[i])
			std::cout << "[" << i << "] : " << this->list[i]->getType() << std::endl;
		else
			std::cout << "[" << i << "] : " << "(empty)" << std::endl;
	}
	std::cout << std::endl;
}
