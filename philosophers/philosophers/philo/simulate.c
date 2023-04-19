/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/19 23:45:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_philo_print(t_philo *philo, char *str)
{
	int	timestamp;

	pthread_mutex_lock(&(philo->share->share_lock));
	timestamp = (int)(get_current_time() - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(&(philo->share->share_lock));
}

static int	_philo_sleep(long long wait_time, t_philo *philo)
{
	long long	sleep_start;
	long long	sleep_total;

	sleep_start = get_current_time();
	sleep_total = wait_time + sleep_start;
	while (get_current_time() < sleep_total)
	{
		if (check_philo_dead(philo) == TRUE)
			return (FALSE);
		usleep(500);
	}
	return (TRUE);
}

static int	_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_lock[0]);
	_philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_lock[1]);
	_philo_print(philo, "has taken a fork");
	if (check_philo_dead(philo) == TRUE)
	{
		pthread_mutex_unlock(philo->fork_lock[1]);
		pthread_mutex_unlock(philo->fork_lock[0]);
		return (FALSE);
	}
	philo->philo_time_last_eat = get_current_time();
	_philo_print(philo, "is eating");
	if (_philo_sleep(philo->share->args.philo_time_eat, philo) == FALSE)
	{
		pthread_mutex_unlock(philo->fork_lock[1]);
		pthread_mutex_unlock(philo->fork_lock[0]);
		return (FALSE);
	}
	pthread_mutex_unlock(philo->fork_lock[1]);
	pthread_mutex_unlock(philo->fork_lock[0]);
	return (TRUE);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->philo_time_last_eat = get_current_time();
	// should take only one philo
	if (philo->philo_id & 1)
	{
		_philo_print(philo, "is thinking");
		_philo_sleep(philo->share->args.philo_time_eat, philo);
	}
	while (philo->philo_count_eat-- != 0)
	{
		if (_eating(philo) == FALSE)
			break ;
		_philo_print(philo, "is sleeping");
		if (_philo_sleep(philo->share->args.philo_time_sleep, philo) == FALSE)
			break ;
		_philo_print(philo, "is thinking");
		usleep(100);
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
