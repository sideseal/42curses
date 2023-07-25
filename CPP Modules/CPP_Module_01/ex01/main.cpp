/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:45:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/25 22:26:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifdef LEAKS_CHECK
#include <cstdlib>
void	check_leaks(void)
{
	system("leaks --list -- zombieHorde");
}
#define ATEXIT_CHECK() atexit(check_leaks)
#else
#define ATEXIT_CHECK()
#endif

int	main(int argc, char* argv[])
{
	std::size_t	N = 10;

	ATEXIT_CHECK();
	if (argc == 2)
	{
		std::istringstream iss(argv[1]);
		if (!(iss >> N) || N > static_cast<std::size_t>(std::numeric_limits<int>::max()))
		{
			std::cout << "Invalid number: " << argv[1] << std::endl;
			return (1);
		}
		else if (!iss.eof()) {
			std::cout << "Trailing characters after number: " << argv[1] << std::endl;
			return (1);
		}
	}
	Zombie*	horde = zombieHorde(static_cast<int>(N), "ZombieHorde");

	for (std::size_t i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
