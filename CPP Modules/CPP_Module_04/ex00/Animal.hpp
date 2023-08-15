/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:02:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/15 18:57:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__
# include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const& target);
		Animal&	operator=(Animal const& target);

		virtual std::string	getType(void) const;

		virtual void	makeSound(void) const;
};

#endif	/* __ANIMAL_HPP__ */
