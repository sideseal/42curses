/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:49:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 23:34:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class	Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	inventory[4];

	public:
		Character(void);
		virtual ~Character(void);
		Character(std::string const& name);
		Character(Character const& target);
		Character&	operator=(Character const& target);

		virtual std::string const&	getName() const;

		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif
