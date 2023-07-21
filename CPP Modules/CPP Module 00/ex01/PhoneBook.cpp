/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:08:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/21 19:08:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int PhoneBook::_index = 0;

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
		_contacts[i] = Contact(i);
}

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

static void	convertToUppercase(std::string& str)
{
	size_t	length = str.length();
	for (size_t i = 0; i < length; i++)
		str[i] = std::toupper(str[i]);
}

void	PhoneBook::UsePhoneBook(void)
{
	std::string	input;

	PrintUsage();
	while (true)
	{

		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (!std::cin.good())
			exit(1);
		convertToUppercase(input);
		if (input == "EXIT")
		{
			PrintExit();
			break;
		}
		else if (input == "ADD")
		{
			UpdatePhoneBook();
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

void	PhoneBook::UpdatePhoneBook(void)
{
	_contacts[_index].MakeContact();
	_index = (_index + 1) % 8;
}

static bool	isOneDigitNumber(const std::string& str)
{
	return ((str.length() == 1) && std::isdigit(static_cast<unsigned char>(str[0])));
}

static void	showContactList(Contact* _contacts)
{
	std::cout << "| " << std::setw(10) << "index" << " ";
	std::cout << "| " << std::setw(10) << "first name" << " ";
	std::cout << "| " << std::setw(10) << "last name" << " ";
	std::cout << "| " << std::setw(10) << "nickname" << " |" << std::endl;
	for (size_t i = 0; i < 8; i++)
		_contacts[i].DisplayBriefContact();
}

void	PhoneBook::SearchPhoneBook(void)
{
	int			index;
	bool		flag;
	std::string	input;

	flag = true;
	while (flag)
	{
		showContactList(_contacts);
		while (true)
		{
			std::cout << "Index: " << std::flush;
			std::getline(std::cin, input);
			if (!std::cin.good())
				exit(1);
			if (!input.empty() && isOneDigitNumber(input))
			{
				index = input[0] - '0';
				if (0 <= index && index <= 7)
				{
					_contacts[index].DisplayContact();
					break;
				}
			}
			std::cout << "Error: Invalid index." << std::endl;
		}
		input.clear();
		while (true)
		{
			std::cout << "Search for more contacts? [y/n]" << std::endl;
			std::getline(std::cin, input);
			if (!std::cin.good())
				exit(1);
			if (input == "y")
				break;
			else if (input == "n")
			{
				flag = false;
				std::cout << std::endl;
				break;
			}
			else
				continue;
		}
		input.clear();
	}
}
