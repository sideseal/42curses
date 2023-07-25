/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:18:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 22:02:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	setType(type);
}

const std::string&	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
}
