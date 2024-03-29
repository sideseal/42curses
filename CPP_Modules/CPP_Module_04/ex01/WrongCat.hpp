/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:05:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 21:46:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private:
		std::string	name;

	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		explicit WrongCat(std::string name);
		WrongCat(WrongCat const& target);
		WrongCat&	operator=(WrongCat const& target);

		virtual std::string	getType(void) const;
		std::string			getName(void) const;

		void	makeSound(void) const;
};

#endif	/* __WRONGCAT_HPP__ */
