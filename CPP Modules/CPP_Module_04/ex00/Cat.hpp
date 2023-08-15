/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:05:09 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/15 19:32:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
# define __CAT_HPP__
# include "Animal.hpp"

class	Cat : public Animal
{
	private:
		std::string	name;

	public:
		Cat(void);
		explicit Cat(std::string name);
		virtual ~Cat(void);
		Cat(Cat const& target);
		Cat&	operator=(Cat const& target);

		virtual std::string	getType(void) const;
		std::string			getName(void) const;

		virtual void	makeSound(void) const;
};

#endif	/* __CAT_HPP__ */
