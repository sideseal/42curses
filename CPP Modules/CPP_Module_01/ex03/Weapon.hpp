/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:17:30 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 21:52:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

class	Weapon
{
	public:
		Weapon(const std::string& type);
		const std::string&	getType(void) const;
		void				setType(const std::string& type);

	private:
		std::string	_type;
};

#endif
