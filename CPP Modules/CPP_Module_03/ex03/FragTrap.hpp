/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:18:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/11 22:00:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FTAGTRAP_HPP__

#include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const& name);
		FragTrap(FragTrap const& target);
		FragTrap& operator=(FragTrap const& target);
		virtual ~FragTrap(void);

		virtual void	introduce(void);
		void			highFivesGuys(void);
};

#endif /* __FRAGTRAP_HPP__ */
