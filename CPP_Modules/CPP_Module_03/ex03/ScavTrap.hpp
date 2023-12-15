/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:53:28 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 22:00:45 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
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

#endif	/* __SCAVTRAP_HPP__ */
