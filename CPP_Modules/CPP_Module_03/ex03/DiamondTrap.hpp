/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:23:34 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 20:37:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string const	name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string const& name);
		DiamondTrap(DiamondTrap const& target);
		DiamondTrap& operator=(DiamondTrap const& target);
		virtual ~DiamondTrap(void);

		virtual std::string	getName(void) const;
		virtual void		introduce(void);
		void				whoAmI(void);
};

#endif /* __DIAMONDTRAP_HPP__ */
