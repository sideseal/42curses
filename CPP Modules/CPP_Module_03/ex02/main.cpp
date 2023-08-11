/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:14 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 22:33:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void	testCaseOne(void)
{
	ScavTrap	scavOne("ScavOne");
	FragTrap	fragOne("FragOne");
	int			round = 0;

	while (scavOne.getEnergy() && fragOne.getEnergy())
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		unsigned int	prevEnergy = scavOne.getEnergy();
		scavOne.attack(fragOne.getName());
		if (prevEnergy != 0)
			fragOne.takeDamage(scavOne.getAttack());
		prevEnergy = fragOne.getEnergy();
		fragOne.attack(scavOne.getName());
		if (prevEnergy != 0)
			scavOne.takeDamage(fragOne.getAttack());
		std::cout << std::endl;
	}
}

void	testCaseTwo(void)
{
	FragTrap	fragTwo("FragTwo");
	int			round = 0;

	while (round < 5)
	{
		std::cout << "Round " << round++ + 1 << std::endl;

		fragTwo.highFivesGuys();
		fragTwo.beRepaired(10);
		std::cout << std::endl;
	}
}

void	testCaseThree(void)
{
	FragTrap	fragThree("FragThree");
	FragTrap	fragFour(fragThree);
	ClapTrap*	cp = &fragFour;

	fragThree.attack(cp->getName());
	cp->attack(fragThree.getName());
	std::cout << std::endl;
}

void	testCaseFour(void)
{
	ClapTrap*	clapTwo = new FragTrap("FragFive");

	delete clapTwo;
}

void	testCaseFive(void)
{
	ScavTrap*	scavTwo = new ScavTrap();
	FragTrap*	fragSix = dynamic_cast<FragTrap*>(scavTwo);

	std::cout << "dynamic casting between non-connective classes: " << fragSix << std::endl;
	delete scavTwo;
}

void	testCaseSix(void)
{
	ClapTrap*	clapThree = new FragTrap();
	FragTrap*	fragSeven = dynamic_cast<FragTrap*>(clapThree);

	std::cout << "dynamic casting between Base-Derieve classes: " << fragSeven << std::endl;
	fragSeven->highFivesGuys();
	delete clapThree;
}

int	main(void)
{
	std::cout << "Case 1: Violence" << std::endl;
	testCaseOne();
	std::cout << '\n' << "Case 2: I love you guys!" << std::endl;
	testCaseTwo();
	std::cout << '\n' << "Case 3: Up-Casting" << std::endl;
	testCaseThree();
	std::cout << '\n' << "Case 4: Dynamic allocation with Up-Casting" << std::endl;
	testCaseFour();
	std::cout << '\n' << "Case 5: Dynamic Casting in non-connective classes" << std::endl;
	testCaseFive();
	std::cout << '\n' << "Case 6: Dynamic Casting with Up-Casting" << std::endl;
	testCaseSix();
	return (EXIT_SUCCESS);
}
