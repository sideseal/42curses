/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/31 23:23:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("%d, [%d, %d, %d, %d]\n", philo->philo_name, philo->resources.forks[0], philo->resources.forks[1], philo->resources.forks[2], philo->resources.forks[3]);
	return ((void *)0);
}

// need exception
void	start_simulation(t_context context, t_philo *philos)
{
	int		i;

	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_create(&(philos[i].philo_thread), NULL, \
			test, (void *)&(philos[i])) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_context		context;
	t_philo			*philos;
	t_resource		resources;

	if (argc < 5 || argc > 6 || !check_valid_input(argv))
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	init_context(&context, argv);
	init_resources(&resources, context);
	init_philos(&philos, context, resources);
	start_simulation(context, philos);
	return (0);
}
