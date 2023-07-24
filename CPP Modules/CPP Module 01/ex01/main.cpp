/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:45:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/24 23:19:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifdef LEAKS_CHECK
#include <cstdlib>
void	check_leaks(void)
{
	system("leaks --list -- Zombie");
}
#define ATEXIT_CHECK() atexit(check_leaks)
#else
#define ATEXIT_CHECK()
#endif

int	main(void)
{
	const int	N = 10;

	ATEXIT_CHECK();
	Zombie*	horde = zombieHorde(N, "ZombieHorde");
	
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
