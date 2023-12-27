/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:02:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/25 01:39:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

int	main()
{
	int	iArr[] = {1, 2, 3};

	std::cout << "Testing int array" << std::endl;
	::iter(iArr, ::getArrayLength(iArr), ::display<int>);

	std::cout << std::endl;

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);

	float const	cfArr[] = {-0.42f, 2.04f, 3.0f};

	std::cout << "Testing float const array" << std::endl;
	::iter(cfArr, ::getArrayLength(cfArr), ::display<float>);

	std::cout << std::endl;

	std::string	sArr[] = {"hello", "42", "seoul"};

	std::cout << "Testing string array" << std::endl;
	::iter(sArr, ::getArrayLength(sArr), ::display<std::string>);

	// std::cout << "\n--------------------\n";

	void	(*fp1)(const int&) = reinterpret_cast<void (*)(const int&)>(&::display<int>);
	void	(*fp2)(const std::string&) = reinterpret_cast<void (*)(const std::string&)>(&::display<std::string>);
	void	(*fp3)(const float&) = reinterpret_cast<void (*)(const float&)>(&::display<float>);
	void	(*fp4)(const int&) = reinterpret_cast<void (*)(const int&)>(&::display<int>);

	std::cout << "Template Function(int) fp1 address: " << fp1 << std::endl;
	std::cout << "Template Function(string) fp2 address: " << fp2 << std::endl;
	std::cout << "Template Function(float) fp3 address: " << fp3 << std::endl;
	std::cout << "Template Function(int) fp4 address: " << fp4 << std::endl;
	std::cout << "Template made when different type called! Q.E.D" << std::endl;

	return 0;
}
