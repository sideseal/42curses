/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/12 20:37:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class	ClapTrap
{
	protected:
		std::string const	name;
		int					_hit;
		unsigned int		_energy;
		unsigned int		_attack;

	public:
		ClapTrap(void);
		ClapTrap(std::string const& name);
		ClapTrap(ClapTrap const& target);
		ClapTrap& operator=(ClapTrap const& target);
		virtual ~ClapTrap(void);

		virtual std::string		getName(void) const;
		int						getHit(void) const;
		unsigned int			getEnergy(void) const;
		unsigned int			getAttack(void) const;

		virtual void	attack(std::string const& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		virtual void	introduce(void);
};

#endif	/* __CLAPTRAP_HPP__ */
