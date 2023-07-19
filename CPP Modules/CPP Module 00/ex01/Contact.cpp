/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:09:04 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/19 23:01:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

void	Contact::MakeContact(int index)
{
	_index = index;
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
