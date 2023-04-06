/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/06 23:04:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(philo->fork_mutex[0]);
		*(philo->fork[0]) = 1;
		pthread_mutex_unlock(philo->fork_mutex[0]);
		pthread_mutex_lock(philo->fork_mutex[1]);
		*(philo->fork[1]) = 1;
		pthread_mutex_unlock(philo->fork_mutex[1]);

		usleep(100000);

		pthread_mutex_lock(philo->fork_mutex[0]);
		*(philo->fork[0]) = 0;
		pthread_mutex_unlock(philo->fork_mutex[0]);
		pthread_mutex_lock(philo->fork_mutex[1]);
		*(philo->fork[1]) = 0;
		pthread_mutex_unlock(philo->fork_mutex[1]);

		pthread_mutex_lock(&(philo->resources.print_mutex));
		//printf("%d, [%d, %d, %d, %d]\n", philo->philo_name, philo->resources.forks[0], philo->resources.forks[1], philo->resources.forks[2], philo->resources.forks[3]);
		pthread_mutex_unlock(&(philo->resources.print_mutex));
	}
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
	if (init_context(&context, argv) < 0)
		return (1);
	if (init_resources(&resources, context) < 0)
		return (1);
	if (init_philos(&philos, context, resources) < 0)
		return (1);
	start_simulation(context, philos);
	ft_free_both(resources.forks, resources.forks_mutex);
	free(philos);
	return (0);
}
