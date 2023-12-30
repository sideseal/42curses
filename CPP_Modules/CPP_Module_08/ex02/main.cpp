/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:47:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 03:10:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include "MutantStack.hpp"

void	test_more()
{
	std::cout << "\nMore Tests" << std::endl;

	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	std::cout << "Testing Iterator... w/ value increment\n";
	for (MutantStack<int>::iterator it = mstack.begin();
		 it != mstack.end(); it++)
	{
		std::cout << *it << '\n';
		*it = *it + 1;
	}

	std::cout << "Testing Const Iterator...\n";
	for (MutantStack<int>::const_iterator cit = mstack.begin();
		 cit != mstack.end(); cit++)
	{
		std::cout << *cit << '\n';
	}

	std::cout << "Testing Reverse Iterator...\n";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		 rit != mstack.rend(); rit++)
	{
		std::cout << *rit << '\n';
	}

	std::cout << "Testing Const Reverse Iterator...\n";
	for (MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		 crit != mstack.rend(); crit++)
	{
		std::cout << *crit << '\n';
	}

	std::cout << std::endl;

	std::cout << "MutantStack Copy Test\n";
	std::cout << "Creating const MutantStack : cstack...\n";
	std::cout << "Copying mstack to cstack w/ copy constructor...\n";
	MutantStack<int> const	cstack(mstack);

	std::cout << "Const iterating cstack...\n";
	for (MutantStack<int>::const_iterator cit = cstack.begin();
		 cit != cstack.end(); cit++)
	{
		std::cout << *cit << '\n';
	}
	std::cout << "Const reverse iterating cstack...\n";
	for (MutantStack<int>::const_reverse_iterator crit = cstack.rbegin();
		 crit != cstack.rend(); crit++)
	{
		std::cout << *crit << '\n';
	}

	std::cout << "Copying mstack to nstack with assignment operation...\n";
	MutantStack<int>	nstack;
	nstack = cstack;

	std::cout << "Iterating nstack...\n";
	for (MutantStack<int>::iterator it = nstack.begin();
		 it != nstack.end(); it++)
	{
		std::cout << *it << '\n';
	}
}

void	test_list()
{
	std::cout << "\nList output\n";

	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator	it = lst.begin();
	std::list<int>::iterator	ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>	s(lst);
}

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	test_list();
	test_more();
	return 0;
}
