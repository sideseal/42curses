/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:09:04 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/20 22:03:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(void) {}

Contact::Contact(int index)
{
	_index = index;
}

void	Contact::MakeContact(void)
{
	while (true)
	{
		std::cout << "First name: " << std::flush;
		if (std::getline(std::cin >> std::ws, _firstName) && !_firstName.empty())
			break;
	}
	while (true)
	{
		std::cout << "Last name: " << std::flush;
		if (std::getline(std::cin >> std::ws, _lastName) && !_lastName.empty())
			break;
	}
	while (true)
	{
		std::cout << "nickname: " << std::flush;
		if (std::getline(std::cin >> std::ws, _nickname) && !_nickname.empty())
			break;
	}
	while (true)
	{
		std::cout << "Phone number: " << std::flush;
		if (std::getline(std::cin >> std::ws, _phoneNumber) && !_phoneNumber.empty())
			break;
	}
	while (true)
	{
		std::cout << "Darkest secret: " << std::flush;
		if (std::getline(std::cin >> std::ws, _darkestSecret) && !_darkestSecret.empty())
			break;
	}
	std::cout << "Contact has been created." << '\n' << std::endl;
}

static std::string TruncateString(const std::string& str)
{
	std::string	ret = str;

	if (ret.length() > 10)
		ret = ret.substr(0, 9) + ".";
	return (ret);
}

void	Contact::DisplayBriefContact(void)
{
	std::cout << "| " << std::setw(10) << _index << " ";
	std::cout << "| " << std::setw(10) << TruncateString(_firstName) << " ";
	std::cout << "| " << std::setw(10) << TruncateString(_lastName) << " ";
	std::cout << "| " << std::setw(10) << TruncateString(_nickname) << " |" << std::endl;
}

void	Contact::DisplayContact(void)
{
	std::cout << "First name: " << _firstName << '\n';
	std::cout << "Last name: " << _lastName << '\n';
	std::cout << "Nickname: " << _nickname << '\n';
	std::cout << "Phone number: " << _phoneNumber << '\n';
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
