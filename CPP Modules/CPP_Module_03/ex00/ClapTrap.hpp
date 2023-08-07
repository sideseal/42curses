/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/07 19:17:37 by gychoi           ###   ########.fr       */
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

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif	// CLAPTRAP_H
