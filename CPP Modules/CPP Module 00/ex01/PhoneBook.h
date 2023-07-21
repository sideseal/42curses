/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:08:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/21 18:56:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class	PhoneBook
{
	public:
		PhoneBook();
		void	PrintExit(void);
		void	PrintUsage(void);
		void	PrintInvalid(void);
		void	UsePhoneBook(void);
		void	UpdatePhoneBook(void);
		void	SearchPhoneBook(void);

	private:
		static int	_index;
		Contact		_contacts[8];
};

#endif
