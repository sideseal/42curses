/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:17:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 22:33:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

#ifdef LEAKS_CHECK
#include <cstdlib>
void	check_leaks(void)
{
	system("leaks --list -- violence");
}
#define ATEXIT_CHECK() atexit(check_leaks)
#else
#define ATEXIT_CHECK()
#endif

int	main()
{
	ATEXIT_CHECK();
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
