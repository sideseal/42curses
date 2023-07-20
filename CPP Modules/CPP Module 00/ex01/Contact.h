/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:09:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/20 21:46:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
# include <string>

class	Contact
{
	public:
		Contact(void);
		Contact(int index);
		void	DisplayBriefContact(void);
		void	DisplayContact(void);
		void	MakeContact(void);

	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
