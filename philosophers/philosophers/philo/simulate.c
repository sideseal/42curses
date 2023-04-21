/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 19:05:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_fork(t_philo *philo, int order)
{
	int			take;
	long long	last_eat;

	take = FALSE;
	last_eat = philo->philo_time_last_eat;
	while (get_current_time() - last_eat < philo->share->args.philo_time_die)
	{
		pthread_mutex_lock(philo->fork_lock[order]);
		if (*(philo->forks[order]) == 0)
		{
			*(philo->forks[order]) = 1;
			take = TRUE;
		}
		pthread_mutex_unlock(philo->fork_lock[order]);
		if (take == TRUE)
			return (TRUE);
		usleep(100);
	}
	return (FALSE);
}

void	put_down_fork(t_philo *philo, int order)
{
	pthread_mutex_lock(philo->fork_lock[order]);
	*(philo->forks[order]) = 0;
	pthread_mutex_unlock(philo->fork_lock[order]);
}

static int	_eating(t_philo *philo)
{
	int	eating;

	eating = FALSE;
	if (pick_up_fork(philo, 0) == TRUE)
	{
		philo_print(philo, "has taken a fork");
		if (pick_up_fork(philo, 1) == TRUE)
		{
			philo_print(philo, "has taken a fork");
			philo->philo_time_last_eat = get_current_time();
			philo_print(philo, "is eating");
			eating = TRUE;
			if (philo_sleep(philo->share->args.philo_time_eat, philo) == FALSE)
				eating = FALSE;
			put_down_fork(philo, 1);
		}
		else
			philo_dead(philo);
		put_down_fork(philo, 0);
	}
	else
		philo_dead(philo);
	return (eating);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->share->share_lock));
	pthread_mutex_unlock(&(philo->share->share_lock));
	philo->philo_time_last_eat = get_current_time();
	if (philo->philo_id & 1)
	{
		philo_print(philo, "is thinking");
		philo_sleep(philo->share->args.philo_time_eat, philo);
	}
	while (philo->philo_count_eat-- != 0)
	{
		if (_eating(philo) == FALSE)
			break ;
		philo_print(philo, "is sleeping");
		if (philo_sleep(philo->share->args.philo_time_sleep, philo) == FALSE)
			break ;
		philo_print(philo, "is thinking");
		usleep(500);
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
