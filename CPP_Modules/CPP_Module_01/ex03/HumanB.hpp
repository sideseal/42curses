/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:19:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 22:28:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(const std::string& name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);

	private:
		Weapon*				_weapon;
		const std::string	_name;
};

#endif
