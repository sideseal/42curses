/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:04:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 20:52:44 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
# define __DOG_HPP__
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		std::string	name;
		std::size_t	memory;
		Brain*		brain;

	public:
		Dog(void);
		virtual ~Dog(void);
		explicit Dog(std::string name);
		Dog(Dog const& target);
		Dog&	operator=(Dog const& target);

		virtual std::string	getType(void) const;
		std::string			getName(void) const;
		std::size_t			getMemory(void) const;

		virtual void	makeSound(void) const;
		void			thinking(std::size_t idx) const;
		void			learning(std::string const& idea);
};

#endif	/* __DOG_HPP__ */
