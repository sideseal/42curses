/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:28 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 16:38:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie();
		void	announce(void);

	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
