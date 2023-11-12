/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/11/12 19:30:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

int	main()
{
	std::string	nameInput;
	std::string	gradeInput;
	std::string	name;
	int			grade;

	while (true)
	{
		std::cout << "Enter the bureaucrat name: ";
		std::getline(std::cin, nameInput);

		if (nameInput.empty())
		{
			std::cout << "Invalid input. Name cannot be empty.\n";
		}
		else
		{
			name = nameInput;
			break;
		}
	}

	while (true)
	{
		std::cout << "Enter the bureaucrat grade (1 to 150): ";
		std::getline(std::cin, gradeInput);

		std::istringstream	iss(gradeInput);
		if (!(iss >> grade))
		{
			std::cout << "Invalid input. Please enter a valid integer.\n";
		}
		else
		{
			break;
		}
	}

	try
	{
		Bureaucrat	bureaucrat(name, grade);
		std::cout << bureaucrat << std::endl;

		std::cout << "Increase Grade" << std::endl;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat << std::endl;

		std::cout << "Decrease Grade" << std::endl;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
