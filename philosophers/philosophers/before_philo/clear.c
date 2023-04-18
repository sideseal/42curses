/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:58:19 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/16 23:36:40 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_mutex_array(pthread_mutex_t *mutex_array, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		pthread_mutex_destroy(&(mutex_array)[i]);
	return (-1);
}

int	clear_all_shared_mutex(t_shared *shared)
{
	int	i;

	i = -1;
	while (++i < shared->param.philo_num)
	{
		pthread_mutex_destroy(&(shared->forks_mutex)[i]);
		pthread_mutex_destroy(&(shared->philo_mutex)[i]);
	}
	pthread_mutex_destroy(&(shared->shared_mutex));
	return (-1);
}

int	clear_and_detach_all_thread(t_philo *philos, t_shared *shared)
{
	int	i;

	i = -1;
	while (++i < shared->param.philo_num)
		pthread_detach(philos[i].philo_thread);
	return (clear_all_shared_mutex(shared));
}
