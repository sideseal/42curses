/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:52:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/30 17:52:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void	display(T const& container)
{
	typename T::const_iterator	it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (it == container.begin())
		{
			std::cout << *it;
		}
		else
		{
			std::cout << ", " << *it;
		}
	}
	std::cout << std::endl;
}

int	main()
{
	try
	{
		std::cout << "Testing Vector..." << std::endl;

		std::vector<int>	vec;

		for (size_t i = 0; i < 5; i++)
		{
			vec.push_back(i);
		}

		display(vec);

		std::vector<int>::iterator	it = easyfind(vec, 2);
		std::cout << "find: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Testing List..." << std::endl;

		std::list<int>	lst;

		for (size_t i = 0; i < 5; i++)
		{
			lst.push_back(i * -1);
		}

		display(lst);

		std::list<int>::iterator	it = easyfind(lst, 2);
		std::cout << "find: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Testing Const Deque..." << std::endl;

		int	tmp[] = { 1, 2, 3, 4, 5 };
		std::deque<int> const	cdq(tmp, tmp + sizeof(tmp)/sizeof(tmp[0]));

		display(cdq);

		std::deque<int>::const_iterator	cit = easyfind(cdq, -2);
		std::cout << "find: " << *cit << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
