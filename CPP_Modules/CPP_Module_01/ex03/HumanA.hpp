/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:33:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 22:27:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string& name, const Weapon& weapon);
		void	attack(void);

	private:
		const Weapon&		_weapon;
		const std::string	_name;
};

#endif
