/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:25:23 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 22:12:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_pick_up_fork(t_philo *philo, int order)
{
	int			take;
	long long	last_eat;
	long long	time_die;

	take = FALSE;
	last_eat = philo->philo_time_last_eat;
	time_die = philo->share->args.philo_time_die;
	while (get_current_time(philo) - last_eat < time_die)
	{
		lock(philo->fork_lock[order], philo);
		if (*(philo->forks[order]) == 0)
		{
			*(philo->forks[order]) = 1;
			take = TRUE;
		}
		unlock(philo->fork_lock[order], philo);
		if (take == TRUE)
			return (TRUE);
		if (usleep(100) < 0)
		{
			philo->error = TRUE;
			return (FALSE);
		}
	}
	return (FALSE);
}

static void	_put_down_fork(t_philo *philo, int order)
{
	lock(philo->fork_lock[order], philo);
	*(philo->forks[order]) = 0;
	unlock(philo->fork_lock[order], philo);
}

static int	_eating(t_philo *philo)
{
	int	eating;

	eating = FALSE;
	if (_pick_up_fork(philo, 0) == TRUE)
	{
		philo_print(philo, "has taken a fork");
		if (_pick_up_fork(philo, 1) == TRUE)
		{
			philo_print(philo, "has taken a fork");
			eating = TRUE;
			philo->philo_time_last_eat = get_current_time(philo);
			philo_print(philo, "is eating");
			if (philo_sleep(philo->share->args.philo_time_eat, philo) == FALSE)
				eating = FALSE;
			_put_down_fork(philo, 1);
		}
		else
			philo_dead(philo);
		_put_down_fork(philo, 0);
	}
	else
		philo_dead(philo);
	return (eating);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	lock(&(philo->share->share_lock), philo);
	unlock(&(philo->share->share_lock), philo);
	philo->philo_time_last_eat = get_current_time(philo);
	if (philo->philo_id & 1)
	{
		philo_print(philo, "is thinking");
		philo_sleep(philo->share->args.philo_time_eat, philo);
	}
	while (philo->philo_count_eat-- != 0 && philo->error != TRUE)
	{
		if (_eating(philo) == FALSE)
			break ;
		philo_print(philo, "is sleeping");
		if (philo_sleep(philo->share->args.philo_time_sleep, philo) == FALSE)
			break ;
		philo_print(philo, "is thinking");
		if (usleep(500) < 0)
			philo->error = TRUE;
	}
	return ((void *)&(philo->error));
}

int	simulate(t_philo *philos, t_share *share)
{
	int		i;
	int		flag;
	void	*retval;

	lock(&(share->share_lock), 0);
	i = -1;
	while (++i < share->args.philo_num)
	{
		if (pthread_create(&(philos[i].philo_thread), 0, _routine, \
			(void *)&(philos[i])) != 0)
			return (clear_and_detach_all_thread(philos, share));
	}
	share->philo_start_time = get_current_time(0);
	unlock(&(share->share_lock), 0);
	flag = TRUE;
	i = -1;
	while (++i < share->args.philo_num)
	{
		if (pthread_join(philos[i].philo_thread, &retval) != 0)
			return (clear_and_detach_all_thread(philos, share));
		if (*(int *)retval == TRUE)
			flag = FALSE;
	}
	return (flag);
}
