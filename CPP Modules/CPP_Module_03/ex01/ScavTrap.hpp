/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:53:28 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 01:49:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const& name);
		ScavTrap(ScavTrap const& target);
		ScavTrap& operator=(ScavTrap const& target);
		virtual ~ScavTrap(void);

		virtual void	attack(std::string const& target);
		virtual void	introduce(void);
		void			guardGate(void);
};

#endif	/* __SCAVTRAP_H__ */
