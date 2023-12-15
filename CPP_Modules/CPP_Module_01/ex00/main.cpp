/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 17:06:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifdef LEAKS_CHECK
#include <cstdlib>
void	check_leaks(void)
{
	system("leaks --list -- zombie");
}
#define ATEXIT_CHECK() atexit(check_leaks)
#else
#define ATEXIT_CHECK()
#endif

int	main(void)
{
	ATEXIT_CHECK();
	Zombie*	zombie = newZombie("HeapZombie");

	zombie->announce();
	randomChump("StackZombie");
	delete zombie;
	return (0);
}
