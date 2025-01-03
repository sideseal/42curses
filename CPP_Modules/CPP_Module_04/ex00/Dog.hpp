/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 22:24:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
# define __DOG_HPP__
# include "Animal.hpp"

class	Dog : public Animal
{
	private:
		std::string	name;

	public:
		Dog(void);
		virtual ~Dog(void);
		explicit Dog(std::string name);
		Dog(Dog const& target);
		Dog&	operator=(Dog const& target);

		virtual std::string	getType(void) const;
		std::string			getName(void) const;

		virtual void	makeSound(void) const;
};

#endif	/* __DOG_HPP__ */
