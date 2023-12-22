/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:02:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/22 18:08:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

int	main()
{
	int	iArr[] = {1, 2, 3};

	std::cout << "Testing int array" << std::endl;
	::iter(iArr, 3, ::display<int>);

	std::cout << std::endl;

	float const	cfArr[] = {-0.42f, 2.04f, 3.0f};

	std::cout << "Testing float const array" << std::endl;
	::iter(cfArr, 3, ::display<float>);

	std::cout << std::endl;

	std::string	sArr[] = {"hello", "42", "seoul"};

	std::cout << "Testing string array" << std::endl;
	::iter(sArr, 3, ::display<std::string>);

	std::cout << "\n--------------------\n";

	void	(*fp1)(int) = reinterpret_cast<void (*)(int)>(&::display<int>);
	void	(*fp2)(std::string) = reinterpret_cast
								  <void (*)(std::string)>
								  (&::display<std::string>);
	void	(*fp3)(float) = reinterpret_cast
								  <void (*)(float)>
								  (&::display<float>);
	void	(*fp4)(int) = reinterpret_cast<void (*)(int)>(&::display<int>);

	std::cout << "Template Function(int) fp1 address: " << fp1 << std::endl;
	std::cout << "Template Function(string) fp2 address: " << fp2 << std::endl;
	std::cout << "Template Function(float) fp3 address: " << fp3 << std::endl;
	std::cout << "Template Function(int) fp4 address: " << fp4 << std::endl;
	std::cout << "Template made when different type called! Q.E.D" << std::endl;

	return 0;
}
