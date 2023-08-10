/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 01:04:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>

class	ClapTrap
{
	private:
		std::string const	_name;
		int					_hit;
		unsigned int		_energy;
		unsigned int		_attack;

	public:
		ClapTrap(void);
		ClapTrap(std::string const& name);
		ClapTrap(ClapTrap const& target);
		ClapTrap& operator=(ClapTrap const& target);
		~ClapTrap(void);

		std::string		getName(void) const;
		int				getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getAttack(void) const;

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	introduce(void);
};

#endif	/* __CLAPTRAP_H__ */
