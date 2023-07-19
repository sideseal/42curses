/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:08:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/19 22:19:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "Contact.h"

class	PhoneBook
{
	public:
		void	PrintExit(void);
		void	PrintUsage(void);
		void	PrintInvalid(void);
		void	UsePhoneBook(void);
		void	UpdatePhoneBook(Contact contact, int index);
		void	SearchPhoneBook(void);

	private:
		Contact	_contacts[8];
};

#endif
