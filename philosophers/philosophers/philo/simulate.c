/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 01:02:53 by gychoi           ###   ########.fr       */
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

void	*died_lonely(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_lock[0]);
	_philo_print(philo, "has taken a fork");
	_philo_sleep(philo->share->args.philo_time_die, philo);
	_philo_print(philo, "died");
	pthread_mutex_unlock(philo->fork_lock[0]);
	return ((void *)0);
}

int	pick_up_fork(t_philo *philo, int order)
{
	int	take;
	
	take = 0;
	while (get_current_time() - philo->philo_time_last_eat < philo->share->args.philo_time_die)
	{
		pthread_mutex_lock(philo->fork_lock[order]);
		if (*(philo->forks[order]) == 0)
		{
			*(philo->forks[order]) = 1;
			take = 1;
		}
		pthread_mutex_unlock(philo->fork_lock[order]);
		if (take == 1)
			return (TRUE);
//		if (check_philo_dead(philo) == TRUE)
//			return (FALSE);
		usleep(100);
	}
	return (FALSE);
}

static int	_eating(t_philo *philo)
{
	int	result;

	result = FALSE;
	if (pick_up_fork(philo, 0) == TRUE)
	{
		_philo_print(philo, "has taken a fork");
		if (pick_up_fork(philo, 1) == TRUE)
		{
			_philo_print(philo, "has taken a fork");
			philo->philo_time_last_eat = get_current_time();
			_philo_print(philo, "is eating");
			if (_philo_sleep(philo->share->args.philo_time_eat, philo) == FALSE)
				return (FALSE);
			result = TRUE;
			pthread_mutex_lock(philo->fork_lock[1]);
			*(philo->forks[1]) = 0;
			pthread_mutex_unlock(philo->fork_lock[1]);
		}
		else
		{
			pthread_mutex_lock(&(philo->share->share_lock));
			int curr = get_current_time();
			int timestamp = (int)(curr - philo->share->philo_start_time);
			if (!philo->share->stop)
				printf("%d %d died\n", timestamp, philo->philo_id);
			philo->share->stop = 1;
			pthread_mutex_unlock(&(philo->share->share_lock));
		}
		pthread_mutex_lock(philo->fork_lock[0]);
		*(philo->forks[0]) = 0;
		pthread_mutex_unlock(philo->fork_lock[0]);
	}
	else
	{
		pthread_mutex_lock(&(philo->share->share_lock));
		int curr = get_current_time();
		int timestamp = (int)(curr - philo->share->philo_start_time);
		if (!philo->share->stop)
			printf("%d %d died\n", timestamp, philo->philo_id);
		philo->share->stop = 1;
		pthread_mutex_unlock(&(philo->share->share_lock));
	}
	return (result);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->philo_time_last_eat = get_current_time();
	if (philo->share->args.philo_num == 1)
		return (died_lonely(philo));
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
