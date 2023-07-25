/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:45:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 18:55:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class	Zombie
{
	public:
		~Zombie();
		void		announce(void);
		void		setName(const std::string& name);
		std::string	getName(void) const;

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
