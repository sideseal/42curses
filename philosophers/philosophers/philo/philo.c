/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/07 17:51:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_philo *philo)
{
	int	status[2];
	int	flag;

	flag = 1;
	while (flag)
	{
		status[0] = *(philo->fork[0]);
		status[1] = *(philo->fork[1]);
		if (status[0] && status[1])
		{
			pthread_mutex_lock(philo->fork_mutex[0]);
			pthread_mutex_lock(philo->fork_mutex[1]);
			*(philo->fork[0]) = 1;
			*(philo->fork[1]) = 1;
			pthread_mutex_unlock(philo->fork_mutex[0]);
			pthread_mutex_unlock(philo->fork_mutex[1]);
			flag = 0;
		}
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->philo_is_dead)
	{
		pthread_mutex_lock(philo->fork_mutex[0]);
		pthread_mutex_lock(philo->fork_mutex[1]);
		*(philo->fork[0]) = 1;
		*(philo->fork[1]) = 1;
		pthread_mutex_unlock(philo->fork_mutex[0]);
		pthread_mutex_unlock(philo->fork_mutex[1]);

		//pick_up_forks(philo);

		usleep(100000);

		pthread_mutex_lock(philo->fork_mutex[0]);
		pthread_mutex_lock(philo->fork_mutex[1]);
		*(philo->fork[0]) = 0;
		*(philo->fork[1]) = 0;
		pthread_mutex_unlock(philo->fork_mutex[0]);
		pthread_mutex_unlock(philo->fork_mutex[1]);

		pthread_mutex_lock(&(philo->resources.print_mutex));
		//printf("%d, [%d, %d, %d, %d]\n", philo->philo_name, philo->resources.forks[0], philo->resources.forks[1], philo->resources.forks[2], philo->resources.forks[3]);
		pthread_mutex_unlock(&(philo->resources.print_mutex));
	}
	return ((void *)0);
}

// need exception
void	simulation(t_context context, t_philo *philos, t_resource resources)
{
	int		i;

	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_create(&(philos[i].philo_thread), NULL, \
			routine, (void *)&(philos[i])) != 0)
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

