/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:10:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 22:49:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

#ifdef LEAKS_CHECK
# include <cstdlib>
void	check_leaks(void)
{
	system("leaks a.out");
}
# define ATEXIT_CHECK() atexit(check_leaks)
#else
# define ATEXIT_CHECK()
#endif

int	main(void)
{
	return 0;
}
