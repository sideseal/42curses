/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/07 17:49:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_context		context;
	t_philo			*philos;
	t_resource		resources;

	//atexit(check_leaks);
	if (argc < 5 || argc > 6 || !check_valid_input(argv))
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	if (init_context(&context, argv) < 0 \
		|| init_resources(&resources, context) < 0 \
		|| init_philos(&philos, context, resources) < 0)
	{
		printf("Initialize Failed. Abort.\n");
		return (1);
	}
	simulation(context, philos, resources);
	ft_free_both(resources.forks, resources.forks_mutex);
	free(philos);
	return (0);
}
