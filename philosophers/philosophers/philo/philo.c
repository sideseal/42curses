/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/30 22:50:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *data)
{
	t_philo			*philo;
	pthread_mutex_t	lock;
	pthread_mutex_t	p_lock;

	philo = (t_philo *)data;
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_init(&p_lock, NULL);
	while (1)
	{
		pthread_mutex_lock(&p_lock);
		printf("%d %d %d %d\n", philo->forks[0], philo->forks[1], philo->forks[2], philo->forks[3]);
		pthread_mutex_unlock(&p_lock);
		if (*(philo->fork[0]) == 0 && *(philo->fork[1]) == 0)
		{
			pthread_mutex_lock(&lock);
			*(philo->fork[0]) = philo->philo_name;
			pthread_mutex_unlock(&lock);
			pthread_mutex_lock(&lock);
			*(philo->fork[1]) = philo->philo_name;
			pthread_mutex_unlock(&lock);
		}
		usleep(1000);
		pthread_mutex_lock(&lock);
		*(philo->fork[1]) = 0;
		pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock);
		*(philo->fork[0]) = 0;
		pthread_mutex_unlock(&lock);
		usleep(1000 *100);
	}
	return ((void *)0);
}

void start_simulation(t_philo *philosophers, t_context context)
{
	int	i;

	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_create(&(philosophers[i].philo), \
			NULL, test, (void *)&(philosophers[i])) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_join(philosophers[i].philo, NULL) != 0)
			return ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_context	context;
	t_philo		*philosophers;

	if (argc < 5 || argc > 6 || !check_valid_input(argv))
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	init_context(&context, argv);
	init_philo(&philosophers, context);
	start_simulation(philosophers, context);
	return (0);
}
