/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:09:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/19 23:01:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

class	Contact
{
	public:
		Contact();
		void	Print() {
			std::cout << _index << std::endl;
			std::cout << _firstName << std::endl;
			std::cout << _lastName << std::endl;
			std::cout << _nickname << std::endl;
			std::cout << _darkestSecret << std::endl;
		} // need to delete
		void	MakeContact(int index);

	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
