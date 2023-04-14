/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:58:19 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/15 01:01:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_shared_mutex(t_shared *shared, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(&(shared->forks_mutex)[i]);
		pthread_mutex_destroy(&(shared->philo_mutex)[i]);
		i++;
	}
	return (-1);
}

int	clear_all_mutex(t_shared *shared)
{
	int	i;

	i = 0;
	while (i < shared->param.philo_num)
	{
		pthread_mutex_destroy(&(shared->forks_mutex)[i]);
		pthread_mutex_destroy(&(shared->philo_mutex)[i]);
		i++;
	}
	pthread_mutex_destroy(&(shared->shared_mutex));
	return (-1);
}

int	clear_and_detach_all_thread(t_philo *philos, t_shared *shared)
{
	int	i;

	i = 0;
	while (i < shared->param.philo_num)
	{
		pthread_detach(philos[i].philo_thread);
		i++;
	}
	return (clear_all_mutex(shared));
}
