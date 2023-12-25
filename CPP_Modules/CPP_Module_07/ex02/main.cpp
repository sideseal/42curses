/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:42:03 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/25 22:33:46 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"

void	checkLeaks()
{
	system("leaks a.out");
}

int	main()
{
	atexit(checkLeaks);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(1);

	std::cout << "My Array Test" << std::endl;

	std::cout << "\n[Creating Empty Array...]" << std::endl;
	Array<int>	empty;
	std::cout << "addr: " << empty << ", size: " << empty.size() << std::endl;

	std::cout << "\n[Creating Int Array...]" << std::endl;
	Array<int>	ia(3);
	std::cout << "addr: " << ia << ", size: " << ia.size() << std::endl;
	for (size_t i = 0; i < ia.size(); i++)
	{
		std::cout << "storing " << i + 1 << "..." << std::endl;
		ia[i] = i + 1;
	}
	for (size_t i = 0; i < ia.size(); i++)
	{
		std::cout << "index: " << i << ", value: " << ia[i] << std::endl;
	}

	std::cout << "\n[Array Copying Test...]" << std::endl;
	std::cout << "[Creating Negative Int Array...]" << std::endl;
	Array<int>	nia(5);
	std::cout << "addr: " << nia << ", size: " << nia.size() << std::endl;
	for (int i = 0; i < static_cast<int>(nia.size()); i++)
	{
		std::cout << "storing " << (i + 1) * -1 << "..." << std::endl;
		nia[i] = (i + 1) * -1;
	}
	for (size_t i = 0; i < nia.size(); i++)
	{
		std::cout << "index: " << i << ", value: " << nia[i] << std::endl;
	}
	std::cout << "\n[Copying Negative Int Array to Int Array...]" << std::endl;
	ia = nia;
	std::cout << "addr: " << ia << ", size: " << ia.size() << std::endl;
	for (size_t i = 0; i < ia.size(); i++)
	{
		std::cout << "index: " << i << ", value: " << ia[i] << std::endl;
	}

	std::cout << "\n[Creating Float Array...]" << std::endl;
	Array<float>	fa(5);
	std::cout << "addr: " << fa << ", size: " << fa.size() << std::endl;
	for (size_t i = 0; i < fa.size(); i++)
	{
		std::cout << "storing " << i + 1.1f << "..." << std::endl;
		fa[i] = i + 1.1f;
	}
	for (size_t i = 0; i < fa.size(); i++)
	{
		std::cout << "index: " << i << ", value: " << fa[i] << std::endl;
	}

	std::cout << "\n[Creating String Array...]" << std::endl;
	Array<std::string>	sa(3);
	std::cout << "addr: " << sa << ", size: " << sa.size() << std::endl;
	std::cout << "Storing \"hello\"..." << std::endl;
	sa[0] = std::string("hello");
	std::cout << "Storing \"42\"..." << std::endl;
	sa[1] = std::string("42");
	std::cout << "Storing \"seoul\"..." << std::endl;
	sa[2] = std::string("seoul");
	for (size_t i = 0; i < sa.size(); i++)
	{
		std::cout << "index: " << i << ", value: " << sa[i] << std::endl;
	}

	std::cout << "\n[Testing Range of Index...]" << std::endl;
	std::cout << "addr: " << ia << ", size: " << ia.size() << std::endl;
	try
	{
		std::cout << "Storing " << 42
				  << " to index " << ia.size() << "..." << std::endl;
		ia[ia.size()] = 42;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Storing " << -42
				  << " to index " << -1 << "..." << std::endl;
		ia[-1] = 42;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating Array with Invalid Index (-1)..." << std::endl;
		Array<int>	invalid(-1);
		std::cout << "addr: " << invalid << std::endl; // unreached
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n[Testing 'size' Member Function division...]" << std::endl;
	unsigned int	tmp = ia.size();
	std::cout << "ia.size(): " << ia.size() << ", tmp: " << tmp << std::endl;
	std::cout << "Incrementing tmp..." << std::endl;
	tmp++;
	// ia.size()++; // error: expression is not assignable
	std::cout << "ia.size(): " << ia.size() << ", tmp: " << tmp << std::endl;

	return 0;
}
