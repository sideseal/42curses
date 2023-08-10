/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:14 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 01:38:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

void	testCaseTwo(std::string input)
{
	if (input.empty())
		std::cout << "WARNING: The name of the ClapTrap being created is not visible." << std::endl;
	ClapTrap	clapUser(input);
	ClapTrap	clapOne("ClapOne");

	std::cout << "Case : Tug of War" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;

		unsigned int	prevEnergy = clapOne.getEnergy();
		clapOne.attack(input);
		if (prevEnergy != 0)
			clapUser.takeDamage(clapOne.getAttack());
		std::cout << std::endl;

		prevEnergy = clapUser.getEnergy();
		clapUser.attack(clapOne.getName());
		if (prevEnergy != 0)
			clapOne.takeDamage(clapUser.getAttack());
		std::cout << std::endl;
	}
}

void	testCaseOne(void)
{
	std::cout << "Case 1 : Tug of War" << std::endl;
	ClapTrap	clapOne("ClapOne");
	ClapTrap	clapTwo("ClapTwo");

	for (int i = 0; i < 11; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;

		unsigned int	prevEnergy = clapOne.getEnergy();
		clapOne.attack(clapTwo.getName());
		if (prevEnergy != 0)
			clapTwo.takeDamage(clapOne.getAttack());
		std::cout << std::endl;

		prevEnergy = clapTwo.getEnergy();
		clapTwo.attack(clapOne.getName());
		if (prevEnergy != 0)
			clapOne.takeDamage(clapTwo.getAttack());
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case 2 : Self-harm" << std::endl;
	ClapTrap	clapThree("ClapThree");

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapThree.takeDamage(2);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case 3 : Over-heal" << std::endl;
	ClapTrap	clapFour("ClapFour");

	for (int i = 0; i < 11; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapFour.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case 4 : Already Exhausted" << std::endl;
	ClapTrap	clapFive(clapFour);

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapFive.takeDamage(0);
		clapFive.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case 5 : Already Destroyed" << std::endl;
	ClapTrap	clapSix;
	clapSix = clapThree;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapSix.takeDamage(0);
		clapSix.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case 6 : Ultra Violence" << std::endl;
	ClapTrap	clapSeven("ClapSeven");

	clapSeven.takeDamage(3333333333);
	std::cout << "Current " << clapSeven.getName() << " points of health is " << clapSeven.getHit() << std::endl;
	std::cout << '\n' << std::endl;

	std::cout << "Case 7 : Ultra Recovery" << std::endl;
	ClapTrap	clapEight("ClapEight");

	clapEight.beRepaired(3333333333);
	std::cout << "Current " << clapEight.getName() << " points of health is " << clapEight.getHit() << std::endl;
	std::cout << std::endl;
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
		testCaseOne();
	else if (argc == 2)
		testCaseTwo(argv[1]);
	else
	{
		std::cout << "Only one argument is allowed." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
