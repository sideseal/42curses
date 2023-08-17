/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:12:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 21:58:36 by gychoi           ###   ########.fr       */
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

/*
 * main.cpp:40:27: error: allocating an object of abstract class type 'Animal'
 *       const Animal*   meta = new Animal();
 *                                ^
 * ./Animal.hpp:31:16: note: unimplemented pure virtual method 'makeSound' in 'Animal'
 *              virtual void    makeSound(void) const = 0;
 *                             ^
 * 1 error generated.
 * make: *** [main.o] Error 1
 */
void	subjectTest(void)
{
//	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
//	meta->makeSound();

//	delete meta;
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
	Animal*	animal = new Dog("narong");
	Dog*	dog = static_cast<Dog*>(animal);

	std::cout << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << dog->getType() << ", " << dog->getName() << std::endl;
	dog->makeSound();

//	Animal	animalTest = dynamic_cast<Animal>(dog);
	delete animal;
}

int	main(void)
{
	ATEXIT_CHECK();
	makeTestName("Test : Subject Test");
	subjectTest();
	makeTestName("Test 1 : Wrong Animals");
	testOne();
	makeTestName("Test 2 : Casting");
	testTwo();
	return 0;
}
