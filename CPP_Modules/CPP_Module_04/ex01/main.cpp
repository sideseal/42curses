/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:12:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 21:24:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#ifdef LEAKS_CHECK
# include <cstdlib>
void	check_leaks(void)
{
	system("leaks a.out");
}
# define ATEXIT_CHECK() atexit(check_leaks)
#else
# define ATEXIT_CHECK()
#endif

void	makeTestName(std::string const& str)
{
	std::cout << "\n--------------------" << std::endl;
	std::cout << str << std::endl;
	std::cout << "--------------------\n" << std::endl;
}

void	subjectTest(void)
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;
	delete i;
}

void	testOne(Animal const* animalArr[])
{
	Cat const*		catPtr = 0;
	Dog const*		dogPtr = 0;

	if (animalArr[0]->getType() == "Cat") {
		catPtr = static_cast<Cat const*>(animalArr[0]);
		std::cout << catPtr->getType() << std::endl;
		catPtr->makeSound();
	}
	else if (animalArr[0]->getType() == "Dog") {
		dogPtr = static_cast<Dog const*>(animalArr[0]);
		std::cout << dogPtr->getType() << std::endl;
		dogPtr->makeSound();
	}
	else
		std::cout << "[INFO] : Weird animal detects in the animalArr" << std::endl;

	if (animalArr[1]->getType() == "Cat") {
		catPtr = static_cast<Cat const*>(animalArr[1]);
		std::cout << catPtr->getType() << std::endl;
		catPtr->makeSound();
	}
	else if (animalArr[1]->getType() == "Dog") {
		dogPtr = static_cast<Dog const*>(animalArr[1]);
		std::cout << dogPtr->getType() << std::endl;
		dogPtr->makeSound();
	}
	else
		std::cout << "[INFO] : Weird animal detects in the animalArr" << std::endl;
}

void	testTwo(Cat* catPtr, Dog* dogPtr)
{
	catPtr->learning("I hate Dog");
	std::cout << catPtr->getMemory() << std::endl;
	dogPtr->learning("I like Cat!");
	std::cout << dogPtr->getMemory() << std::endl;
	catPtr->thinking(catPtr->getMemory() - 1);
	dogPtr->thinking(dogPtr->getMemory() - 1);
	catPtr->learning("I really hate Dog");
	std::cout << catPtr->getMemory() << std::endl;
	dogPtr->learning("I really like Cat!");
	std::cout << dogPtr->getMemory() << std::endl;
	catPtr->thinking(catPtr->getMemory() - 1);
	dogPtr->thinking(dogPtr->getMemory() - 1);
}

void	testThree(Cat* cat, Dog* dog, Cat* catFriend, Dog* dogFriend)
{
	std::cout << "[INFO] : Inside cat's brain..." << std::endl;
	for (std::size_t i = 0; i < cat->getMemory(); i++)
		cat->thinking(i);
	std::cout << cat->getMemory() << std::endl;
	std::cout << "[INFO] : Inside dog's brain..." << std::endl;
	for (std::size_t i = 0; i < dog->getMemory(); i++)
		dog->thinking(i);
	std::cout << dog->getMemory() << std::endl;
	catFriend->learning("Actually, I like Dog!");
	dogFriend->learning("Actually, I hate Cat");
	*cat = *catFriend;
	*dog = *dogFriend;
	std::cout << "[INFO] : Inside cat's brain..." << std::endl;
	for (std::size_t i = 0; i < cat->getMemory(); i++)
		cat->thinking(i);
	std::cout << cat->getMemory() << std::endl;
	std::cout << "[INFO] : Inside dog's brain..." << std::endl;
	for (std::size_t i = 0; i < dog->getMemory(); i++)
		dog->thinking(i);
	std::cout << dog->getMemory() << std::endl;
}

int	main(void)
{
	Animal const*	animalArr[10];

	for (std::size_t i = 0; i < 10; i++) {
		switch (i & 1)
		{
			case 0:
				animalArr[i] = new Cat();
				break;
			case 1:
				animalArr[i] = new Dog();
				break;
		}
	}

	ATEXIT_CHECK();
	makeTestName("Test : Subject Test");
	subjectTest();
	makeTestName("Test 1 : Animal Array Test");
	testOne(animalArr);
	makeTestName("Test 2 : Brain Test");
	Cat*	cat = const_cast<Cat*>(static_cast<Cat const*>(animalArr[0]));
	Dog*	dog = const_cast<Dog*>(static_cast<Dog const*>(animalArr[1]));
	testTwo(cat, dog);
	makeTestName("Test 3 : Deep Copy Test");
	Cat*	catFriend = const_cast<Cat*>(static_cast<Cat const*>(animalArr[2]));
	Dog*	dogFriend = const_cast<Dog*>(static_cast<Dog const*>(animalArr[3]));
	testThree(cat, dog, catFriend, dogFriend);

	std::cout << std::endl;
	for (std::size_t i = 0; i < 10; i++) {
		delete animalArr[i];
	}
	return 0;
}
