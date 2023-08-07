/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:14 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/07 22:02:29 by gychoi           ###   ########.fr       */
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
		clapOne.attack(input);
		clapUser.takeDamage(0);
		std::cout << std::endl;
		clapUser.attack("clapOne");
		clapOne.takeDamage(0);
		std::cout << std::endl;
	}
}

void	testCaseOne(void)
{
	ClapTrap	clapOne("ClapOne");
	ClapTrap	clapTwo("ClapTwo");

	std::cout << "Case 1 : Tug of War" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapOne.attack("clapTwo");
		clapTwo.takeDamage(0);
		std::cout << std::endl;
		clapTwo.attack("clapOne");
		clapOne.takeDamage(0);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap	clapThree("ClapThree");

	std::cout << "Case 2 : Self-harm" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapThree.takeDamage(2);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap	clapFour("ClapFour");

	std::cout << "Case 3 : Over-heal" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapFour.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap	clapFive("ClapFive");
	ClapTrap	clapSix("ClapSix");

	std::cout << "Case 4 : Sadism" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << i + 1 << std::endl;
		clapFive.attack("clapSix");
		clapSix.takeDamage(0);
		clapSix.beRepaired(10);
		std::cout << std::endl;
		clapSix.attack("clapFive");
		clapFive.takeDamage(0);
		clapFive.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap	clapSeven(clapFive);

	std::cout << "Case 5 : Already Exhausted" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		clapSeven.takeDamage(0);
		clapSeven.beRepaired(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap	clapEight;
	clapEight = clapThree;

	std::cout << "Case 6 : Already Destroyed" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		clapEight.takeDamage(0);
		clapEight.beRepaired(10);
		std::cout << std::endl;
	}
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
