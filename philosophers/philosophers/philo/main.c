/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/11 23:20:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_param			param;
	t_philo			*philos;
	t_shared		shared;

	//atexit(check_leaks);
	if (argc < 5 || argc > 6 || !check_valid_input(argv))
		return (philo_abort("Usage: ./philo number_of_philosophers"
				" time_to_die time_to_eat time_to_sleep"
				" [number_of_times_each_philosopher_must_eat]\n"));
	if (init_param(&param, argv) < 0)
		return (philo_abort("Cannot initialize param structure. "));
	if (init_shared(&shared, param) < 0)
	{
		free(shared.forks);
		free(shared.forks_mutex);
		return (philo_abort("Cannot initialize shared structure. "));
	}
	if (init_philos(&philos, param, shared) < 0)
		return (philo_abort("Cannot initialize philos structure. "));
	simulation(param, philos, shared);
	//ft_free_both(resources.forks, resources.forks_mutex);
	//free(philos);
	return (0);
}
