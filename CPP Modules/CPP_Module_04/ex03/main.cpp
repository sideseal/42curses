/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:10:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/18 03:55:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
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

void	testSubject(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	testOne(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	static_cast<MateriaSource*>(src)->showMateria();

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	// 릭이 발생하는 상황이지만, 서브젝트 지에 따라 아무것도 하지 말까...?
	// floor를 만들기...?
	me->equip(tmp);
	delete tmp;

	static_cast<Character*>(me)->showInventory();

	ICharacter*	bob = new Character("bob");

	IMateriaSource*	newSrc = new MateriaSource();
	newSrc->learnMateria(new Cure());

	AMateria*	foo;
	foo = newSrc->createMateria("cure");
	bob->equip(foo);

	static_cast<Character*>(bob)->showInventory();

	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	bob->use(4, *me);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
	delete newSrc;
}

void	testTwo(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria*	foo = src->createMateria("ice");
	AMateria*	bar = src->createMateria("cure");
	std::cout << foo->getType() << std::endl;
	std::cout << bar->getType() << std::endl;
	*foo = *bar;
	std::cout << foo->getType() << std::endl;
	std::cout << bar->getType() << std::endl;
	AMateria*	baz = src->createMateria("ice");
	AMateria*	qux = src->createMateria("AK-47");

	Character*	me = new Character("me");
	Character*	bob = new Character("bob");
	me->equip(foo);
	me->equip(qux);
	bob->equip(bar);
	bob->equip(baz);
	me->showInventory();
	bob->showInventory();
	*me = *bob;
	me->showInventory();
	bob->showInventory();

	Character*	amy = new Character(*bob);
	amy->showInventory();

	Character*	mike = new Character("mike");
	*bob = *mike;
	mike->showInventory();
	bob->showInventory();

	delete src;
	delete me;
	delete bob;
	delete amy;
	delete mike;
}

void	testThree(void)
{
	// ...
}

int	main(void)
{
	ATEXIT_CHECK();
	makeTestName("Test : Subject Test");
	testSubject();
	makeTestName("Test 1 : Check Simple Cases");
	testOne();
	makeTestName("Test 2 : Copy Test");
	testTwo();
	makeTestName("Test 3 : unequip Test");
	testThree();
	return 0;
}
