/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:12:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 21:53:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
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
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	testOne(void)
{
	WrongAnimal const*	cat = new WrongCat("grumpy");
	WrongAnimal const*	meta = new WrongAnimal();

	std::cout << cat->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	cat->makeSound();
	meta->makeSound();

	delete cat;
	delete meta;
}

void	testTwo(void)
{
	Cat const*	cat = new Cat("kitty");
	WrongAnimal const* wrongAnimal = dynamic_cast<WrongAnimal const*>(cat);

	if (!wrongAnimal)
		std::cout << "[INFO] : Cannot convert Cat to WrongAnimal" << std::endl;
	else
		std::cout << "[INFO] : [OK]" << std::endl;
	delete cat;
}

void	testThree(void)
{
	Animal*	animal = new Dog("narong");
	Dog*	dog = static_cast<Dog*>(animal);

	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << ", " << dog->getName() << std::endl;
	delete dog;
}

void	testFour(void)
{
	Dog*		dog = new Dog("ppoppi");
	WrongCat*	wrongCat = reinterpret_cast<WrongCat*>(dog);

	std::cout << wrongCat->getType() << ", " << wrongCat->getName() << std::endl;
	wrongCat->makeSound();
	delete dog;
}

void	testFive(void)
{
	Cat	catOne("toto");
	Cat	catTwo(catOne);

	std::cout << catOne.getType() << ", " << catOne.getName() << std::endl;
	std::cout << catTwo.getType() << ", " << catTwo.getName() << std::endl;

	Dog	dogOne("ddochi");
	Dog	dogTwo("rani");

	dogOne = dogTwo;
	std::cout << dogOne.getType() << ", " << dogOne.getName() << std::endl;
	std::cout << dogTwo.getType() << ", " << dogTwo.getName() << std::endl;
}

void	testSix(void)
{
	Animal*	animalOne = new Cat("Kim Deok bae");
	Cat		catOne(*static_cast<Cat*>(animalOne));

	std::cout << animalOne->getType() << std::endl;
	std::cout << catOne.getType() << ", " << catOne.getName() << std::endl;

	Animal*	animalTwo = new Animal();
	Cat*	catTwo = static_cast<Cat*>(animalTwo);
	Cat		catThree(*catTwo);

	std::cout << animalTwo->getType() << std::endl;
	std::cout << catThree.getType() << ", " << catThree.getName() << std::endl;

	Animal*	animalThree = new Animal();
	Cat		catFour("nyancat");

	catFour = *static_cast<Cat*>(animalThree);

	std::cout << animalThree->getType() << std::endl;
	std::cout << catFour.getType() << ", " << catFour.getName() << std::endl;

	delete animalOne;
	delete animalTwo;
	delete animalThree;
}

int	main(void)
{
	ATEXIT_CHECK();
	makeTestName("Test : subject Test");
	subjectTest();
	makeTestName("Test 1 : Wrong Animals");
	testOne();
	makeTestName("Test 2 : Dynamic casting with irrelevant classes");
	testTwo();
	makeTestName("Test 3 : Up-casting & Down-casting");
	testThree();
	makeTestName("Test 4 : Getting weird with reinterpret casting");
	testFour();
	makeTestName("Test 5 : Copy constructor");
	testFive();
	makeTestName("Test 6 : Getting weird with copy constructor");
	testSix();
	return 0;
}
