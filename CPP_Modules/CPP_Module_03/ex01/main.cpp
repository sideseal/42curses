/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:14 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 19:45:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void	testCaseOne(void)
{
	ScavTrap	scavOne("ScavOne");
	ClapTrap	clapOne("ClapOne");
	int			round = 0;

	while (scavOne.getEnergy() && clapOne.getEnergy())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		scavOne.beRepaired(15);
		clapOne.beRepaired(15);
		unsigned int	prevEnergy = scavOne.getEnergy();
		scavOne.attack(clapOne.getName());
		if (prevEnergy != 0)
			clapOne.takeDamage(scavOne.getAttack());
		prevEnergy = clapOne.getEnergy();
		clapOne.attack(scavOne.getName());
		if (prevEnergy != 0)
			scavOne.takeDamage(clapOne.getAttack());
		std::cout << std::endl;
	}
}

void	testCaseTwo(void)
{
	ScavTrap	scavTwo("ScavTwo");
	int			round = 0;

	while (round < 5)
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		scavTwo.guardGate();
		scavTwo.beRepaired(10);
		std::cout << std::endl;
	}
}

void	testCaseThree(void)
{
	ScavTrap	scavThree("ScavThree");
	ScavTrap	scavFour(scavThree);
	int			round = 0;

	while (scavThree.getEnergy() && scavFour.getEnergy())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		std::cout << "INFO: Original scavThree attacks." << std::endl;
		unsigned int	prevEnergy = scavThree.getEnergy();
		scavThree.attack(scavFour.getName());
		if (prevEnergy != 0)
			scavFour.takeDamage(scavThree.getAttack());
		std::cout << "INFO: scavThree clone attacks." << std::endl;
		prevEnergy = scavFour.getEnergy();
		scavFour.attack(scavThree.getName());
		if (prevEnergy != 0)
			scavThree.takeDamage(scavFour.getAttack());
		std::cout << std::endl;
	}
}

void	testCaseFour(void)
{
	ScavTrap	scavFive("ScavFive");
	ScavTrap	scavSix("ScavSix");
	ClapTrap*	cp = &scavSix;

	scavFive.attack(cp->getName());
	cp->attack(scavFive.getName());
	std::cout << std::endl;
}

void	testCaseFive(void)
{
	ClapTrap*	clapTwo = new ScavTrap();

	clapTwo->attack("dummy");
	delete clapTwo;
}

int	main(void)
{
	std::cout << "Case 1: Unnessesary Violence" << std::endl;
	testCaseOne();
	std::cout << '\n' << "Case 2: Guard the Gate" << std::endl;
	testCaseTwo();
	std::cout << '\n' << "Case 3: Fight with reflection" << std::endl;
	testCaseThree();
	std::cout << '\n' << "Case 4: Up-Casting" << std::endl;
	testCaseFour();
	std::cout << '\n' << "Case 5: Dynamic allocation with Up-Casting" << std::endl;
	testCaseFive();
	return (EXIT_SUCCESS);
}
