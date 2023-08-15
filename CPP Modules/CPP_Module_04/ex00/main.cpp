/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:12:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/15 20:39:31 by gychoi           ###   ########.fr       */
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
	WrongAnimal const*	meta = new WrongAnimal();
	WrongAnimal const*	cat = new WrongCat("grumpy");

	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	meta->makeSound();

	delete meta;
	delete cat;
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
	return 0;
}
