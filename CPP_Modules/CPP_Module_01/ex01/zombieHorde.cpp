/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:46:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 18:40:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*				horde = new Zombie[N];
	std::ostringstream	oss;

	for (int i = 0; i < N; i++)
	{
		oss << name << i;
		horde[i].setName(oss.str());
		oss.clear();
		oss.str("");
	}
	return (horde);
}
