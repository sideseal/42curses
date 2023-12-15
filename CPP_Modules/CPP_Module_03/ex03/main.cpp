/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:14 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 20:46:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

void	testOne(void)
{
	DiamondTrap	dmOne("dmOne");

	dmOne.whoAmI();
}

void	testTwo(void)
{
	DiamondTrap	dmTwo("dmTwo");
	ClapTrap	clapOne("clapOne");
	ScavTrap	scavOne("scavOne");
	FragTrap	fragOne("fragOne");
	int			round = 0;

	while (clapOne.getHit())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		unsigned int	prevEnergy = dmTwo.getEnergy();
		dmTwo.attack(clapOne.getName());
		if (prevEnergy != 0)
			clapOne.takeDamage(dmTwo.getAttack());
		std::cout << std::endl;
	}
	round = 0;
	while (scavOne.getHit())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		unsigned int	prevEnergy = dmTwo.getEnergy();
		dmTwo.attack(scavOne.getName());
		if (prevEnergy != 0)
			scavOne.takeDamage(dmTwo.getAttack());
		std::cout << std::endl;
	}
	round = 0;
	while (fragOne.getHit())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		unsigned int	prevEnergy = dmTwo.getEnergy();
		dmTwo.attack(fragOne.getName());
		if (prevEnergy != 0)
			fragOne.takeDamage(dmTwo.getAttack());
		std::cout << std::endl;
	}
}

void	testThree(void)
{
	DiamondTrap	dmThree("dmThree");
	DiamondTrap	dmClone(dmThree);

	std::cout << "---------------------------" << std::endl;
	std::cout << "DiamondTrap dmThree Status:" << std::endl;
	std::cout << "Hit Point: " << dmThree.getHit() << std::endl;
	std::cout << "Energy Point: " << dmThree.getEnergy() << std::endl;
	std::cout << "Attack Point: " << dmThree.getAttack() << std::endl;
	std::cout << "---------------------------" << std::endl;

	dmThree.attack(dmClone.getName());
	dmClone.takeDamage(dmThree.getAttack());
	dmThree.beRepaired(dmThree.getHit());
	dmThree.guardGate();
	dmThree.highFivesGuys();
	dmThree.whoAmI();
}

void	testFour(void)
{
	DiamondTrap	dmFour("dmFour");

	dmFour.ClapTrap::attack("dummy1");
	dmFour.attack("dummy2");
	dmFour.whoAmI();
}

void	testFive(void)
{
	DiamondTrap*	dmFive = new DiamondTrap("dmFive");

	dmFive->attack("dummy3");
	dmFive->beRepaired(dmFive->getHit());
	dmFive->guardGate();
	dmFive->highFivesGuys();
	dmFive->whoAmI();

	delete dmFive;
}

void	testSix(void)
{
	DiamondTrap	dmSix("dmSix");
	ClapTrap*	cp = &dmSix;

	dmSix.attack(cp->getName());
	cp->attack(dmSix.getName());
	std::cout << std::endl;
}

void	testSeven(void)
{
	ClapTrap*		cp = new DiamondTrap();
	DiamondTrap*	dmSeven = dynamic_cast<DiamondTrap*>(cp);

	std::cout << "dynamic casting between Base-Derieve classes: " << dmSeven << std::endl;
	dmSeven->whoAmI();
	delete dmSeven;
}

int	main(void)
{
	std::cout << "Case 1: Introduce... DiamondTrap" << std::endl;
	testOne();
	std::cout << '\n' << "Case 2: DiamondTrap Massacre" << std::endl;
	testTwo();
	std::cout << '\n' << "Case 3: Freak Show" << std::endl;
	testThree();
	std::cout << '\n' << "Case 4: Two Face" << std::endl;
	testFour();
	std::cout << '\n' << "Case 5: Dynamic Allocation" << std::endl;
	testFive();
	std::cout << '\n' << "Case 6: Up-Casting" << std::endl;
	testSix();
	std::cout << '\n' << "Case 7: Dynamic Casting" << std::endl;
	testSeven();
	return (EXIT_SUCCESS);
}
