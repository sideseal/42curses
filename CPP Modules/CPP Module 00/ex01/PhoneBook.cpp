/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:08:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/19 23:00:36 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

void	PhoneBook::PrintExit(void)
{
	std::cout << "EXIT" << std::endl;
}

void	PhoneBook::PrintUsage(void)
{
	std::cout << "Please enter a command: ADD, SEARCH, EXIT" << '\n';
}

void	PhoneBook::PrintInvalid(void)
{
	std::cout << "Error: Invalid input" << std::endl;
}

void	PhoneBook::UsePhoneBook(void)
{
	int			index = 0;
	std::string	input;

	PrintUsage();
	while (true)
	{

		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			PrintExit();
			break;
		}
		else if (input == "ADD")
		{
			Contact	contact;

			contact.MakeContact(index);
			UpdatePhoneBook(contact, index);
			index = (index + 1) % 8;
			PrintUsage();
		}
		else if (input == "SEARCH")
		{
			SearchPhoneBook();
			PrintUsage();
		}
		else if (!input.empty())
			PrintInvalid();
		else
			continue;
	}
}

void	PhoneBook::UpdatePhoneBook(Contact contact, int index)
{
	_contacts[index] = contact;
}

bool	isOneDigitNumber(const std::string& str)
{
	return ((str.length() == 1) && std::isdigit(static_cast<unsigned char>(str[0])));
}

void	PhoneBook::SearchPhoneBook(void)
{
	int			index;
	bool		flag;
	std::string	input;
	Contact		contact;

	flag = true;
	while (flag)
	{
		while (true)
		{
			std::cout << "Index: " << std::flush;
			std::getline(std::cin, input);
			if (!input.empty() && isOneDigitNumber(input))
			{
				index = input[0] - '0';
				if (0 <= index && index <= 7)
					break;
			}
			std::cout << "Error: Invalid index." << std::endl;
		}
		input.clear();
		contact = _contacts[index];
		contact.Print();
		while (true)
		{
			std::cout << "Search for more contacts? [y/n]" << std::endl;
			std::getline(std::cin, input);
			if (input == "y")
				break;
			else if (input == "n")
			{
				flag = false;
				break;
			}
			else
				continue;
		}
		input.clear();
	}
}
