/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:05:09 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 20:52:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
# define __CAT_HPP__
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		std::string	name;
		std::size_t	memory;
		Brain*		brain;

	public:
		Cat(void);
		virtual ~Cat(void);
		explicit Cat(std::string name);
		Cat(Cat const& target);
		Cat&	operator=(Cat const& target);

		virtual std::string	getType(void) const;
		std::string			getName(void) const;
		std::size_t			getMemory(void) const;

		virtual void	makeSound(void) const;
		void			thinking(std::size_t idx) const;
		void			learning(std::string const& idea);
};

#endif	/* __CAT_HPP__ */
