/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/18 21:21:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_lock[0]);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_lock[1]);
	philo_print(philo, "has taken a fork");
	philo->philo_time_last_eat = get_current_time();
	if (philo->philo_time_last_eat < 0)
		return (FALSE);
	philo->philo_count_eat--;
	philo_print(philo, "is eating");
	philo_sleep(philo->share->args.philo_time_eat, philo);
	pthread_mutex_unlock(philo->fork_lock[1]);
	pthread_mutex_unlock(philo->fork_lock[0]);
	return (TRUE);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_time_last_eat < 0)
		return ((void *)0);
	// should take only one philo
	philo->philo_time_last_eat = get_current_time();
	if (philo->philo_id & 1)
	{
		philo_print(philo, "is thinking");
		philo_sleep(philo->share->args.philo_time_eat, philo);
	}
	while (philo->philo_count_eat--)
	{
		if (!_eating(philo))
			break ;
		philo_print(philo, "is sleeping");
		philo_sleep(philo->share->args.philo_time_sleep, philo);
		philo_print(philo, "is thinking");
	}
	return ((void *)0);
}

int	simulate(t_philo *philos, t_share *share)
{
	int	i;

	pthread_mutex_lock(&(share->share_lock));
	i = 0;
	while (i < share->args.philo_num)
	{
		if (pthread_create(&(philos[i].philo_thread), 0, _routine, \
			(void *)&(philos[i])) != 0)
			return (clear_and_detach_all_thread(philos, share));
		i++;
	}
	share->philo_start_time = get_current_time();
	if (share->philo_start_time < 0)
		return (clear_and_detach_all_thread(philos, share));
	pthread_mutex_unlock(&(share->share_lock));
	i = 0;
	while (i < share->args.philo_num)
	{
		if (pthread_join(philos[i].philo_thread, 0) != 0)
			return (clear_and_detach_all_thread(philos, share));
		i++;
	}
	return (TRUE);
}
