/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:11:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 01:03:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Span.hpp"

void	test()
{
	std::cout << "\nTest 0 : Copy span\n";
	try
	{
		std::cout << "Creating Span(3): sp1...\n";
		Span	sp1 = Span(3);
		std::cout << "Insert element 1 to sp1...\n";
		sp1.addNumber(1);
		std::cout << "Insert element 2 to sp1...\n";
		sp1.addNumber(2);
		std::cout << "Insert element 3 to sp1...\n";
		sp1.addNumber(3);
		std::cout << "Get shortest span in sp1..." << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << "Get longest span in sp1..." << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

		std::cout << "Creating Span(5): sp2...\n";
		Span	sp2 = Span(5);
		std::cout << "Insert element 100 to sp2...\n";
		sp2.addNumber(100);
		std::cout << "Insert element 200 to sp2...\n";
		sp2.addNumber(200);
		std::cout << "Insert element 300 to sp3...\n";
		sp2.addNumber(300);
		std::cout << "Insert element 50 to sp3...\n";
		sp2.addNumber(50);
		std::cout << "Insert element 100 to sp3...\n";
		sp2.addNumber(100);
		std::cout << "Copy sp2 to sp1...\n";
		sp1 = sp2;
		std::cout << "Get shortest span in sp1..." << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << "Get longest span in sp1..." << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

		std::cout << "Creating Span Using Copy Constructor: sp3...\n";
		std::cout << "Copy sp1 to sp3...\n";
		Span	sp3 = Span(sp1);
		std::cout << "Get shortest span in sp3..." << std::endl;
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << "Get longest span in sp3..." << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 1 : Invalid initialize\n";
	try
	{
		std::cout << "Crating Span(-1)..." << std::endl;
		Span	sp = Span(-1);
		std::cout << sp.shortestSpan() << std::endl; // unreachable
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 2 : Insert element to full Span\n";
	try
	{
		std::cout << "Creating Span(3)...\n";
		Span	sp = Span(3);
		std::cout << "Insert element 1...\n";
		sp.addNumber(1);
		std::cout << "Insert element 2...\n";
		sp.addNumber(2);
		std::cout << "Insert element 3...\n";
		sp.addNumber(3);
		std::cout << "Insert element 42..." << std::endl;
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 3 : Lack of numbers to calculate span\n";
	try
	{
		std::cout << "Creating Empty Span...\n";
		Span	sp;
		std::cout << "Get longest span..." << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating Span(1)...\n";
		Span	sp = Span(1);
		std::cout << "Insert element 1...\n";
		sp.addNumber(1);
		std::cout << "Get shortest span..." << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 4 : Normal span test\n";
	try
	{
		std::cout << "Creating Span(42)...\n";
		Span	sp = Span(42);
		std::cout << "Insert element 0...\n";
		sp.addNumber(0);
		std::cout << "Insert element -999...\n";
		sp.addNumber(-999);
		std::cout << "Insert clement 4242...\n";
		sp.addNumber(4242);
		std::cout << "Insert element -999...\n";
		sp.addNumber(-999);
		std::cout << "Insert element -888...\n";
		sp.addNumber(-888);
		std::cout << "Insert element 0...\n";
		sp.addNumber(0);
		std::cout << "Insert element 4242...\n";
		sp.addNumber(4242);
		std::cout << "Insert element 0...\n";
		sp.addNumber(0);
		std::cout << "Get shortest span...\n";
		std::cout << sp.shortestSpan() << '\n';
		std::cout << "Get longest span...\n";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 5 : 10000 nums\n";
	try
	{
		std::cout << "Generating random seeds...\n";
		std::srand(std::time(0));
		std::cout << "Creating Span(10000)...\n";
		Span	sp = Span(10000);
		std::cout << "Insert 10000 random elements...\n";
		for (size_t i = 0; i < 10000; i++)
		{
			sp.addNumber(std::rand());
		}
		std::cout << "Get shortest span...\n";
		std::cout << sp.shortestSpan() << '\n';
		std::cout << "Get longest span...\n";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 6 : add numbers at once\n";
	try
	{
		std::cout << "Creating Span(10000)...\n";
		Span	sp = Span(10000);
		std::cout << "Generating random seeds...\n";
		std::srand(std::time(0));
		std::cout << "Generating random vector(10000)...\n";
		std::vector<int>	randVec;
		randVec.reserve(10000);
		for (size_t i = 0; i < 10000; i++)
		{
			randVec.push_back(std::rand());
		}
		std::cout << "Store random vector numbers to span at once...\n";
		sp.addNumbers(randVec.begin(), randVec.end());
		std::cout << "Get shortest span...\n";
		std::cout << sp.shortestSpan() << '\n';
		std::cout << "Get longest span...\n";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\nTest 7 : Store range check\n";
	try
	{
		std::cout << "Creating Span(10)...\n";
		Span	sp = Span(10);
		std::cout << "Insert element 0...\n";
		sp.addNumber(0);
		std::cout << "Insert element 0...\n";
		sp.addNumber(0);
		std::cout << "Creating all-zero vector(9)...\n";
		std::vector<int>	zeroVec(9, 0);
		std::cout << "Store all-zero vector numbers to span at once...\n";
		sp.addNumbers(zeroVec.begin(), zeroVec.end());
		std::cout << "Get shortest span...\n";
		std::cout << sp.shortestSpan() << '\n';
		std::cout << "Get longest span...\n";
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

int	main()
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	test();

	return 0;
}
