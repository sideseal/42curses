/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:25:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/18 20:55:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_mutex_array(pthread_mutex_t *mutex_array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(&(mutex_array)[i]);
		i++;
	}
	return (FALSE);
}

int	clear_all_mutex(t_share *share)
{
	clear_mutex_array(share->fork_locks, share->args.philo_num);
	pthread_mutex_destroy(&(share->share_lock));
	return (FALSE);
}

int	clear_and_detach_all_thread(t_philo *philos, t_share *share)
{
	int	i;

	i = 0;
	while (i < share->args.philo_num)
	{
		pthread_detach(philos[i].philo_thread);
		i++;
	}
	return (clear_all_mutex(share));
}
