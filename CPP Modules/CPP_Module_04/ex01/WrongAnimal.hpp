/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:58 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/15 18:57:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__
# include <string>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(WrongAnimal const& target);
		WrongAnimal&	operator=(WrongAnimal const& target);

		virtual std::string	getType(void) const;

		void	makeSound(void) const;
};

#endif	/* __WRONGANIMAL_HPP__ */
