/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:14:10 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/17 20:02:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_mutex[0]);
	philo_print(philo, "has taken a fork");
	*(philo->fork[0]) = 1;
	pthread_mutex_lock(philo->fork_mutex[1]);
	philo_print(philo, "has taken a fork");
	*(philo->fork[1]) = 1;
	return (1);
}

void	_put_down_forks(t_philo *philo)
{
	*(philo->fork[1]) = 0;
	pthread_mutex_unlock(philo->fork_mutex[1]);
	*(philo->fork[0]) = 0;
	pthread_mutex_unlock(philo->fork_mutex[0]);
}

int	eating(t_philo *philo)
{
	if (!_pick_up_forks(philo))
		return (0);
	pthread_mutex_lock(philo->philo_mutex);
	philo->philo_last_eat = get_current_time();
	philo->philo_count_eat--;
	pthread_mutex_unlock(philo->philo_mutex);
	philo_print(philo, "is eating");
	philo_sleep(philo->shared->param.philo_time_eat);
	_put_down_forks(philo);
	return (1);
}

void	sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	philo_sleep(philo->shared->param.philo_time_sleep);
}

void	thinking(t_philo *philo)
{
	philo_print(philo, "is thinking");
}
