/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/12 22:13:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// mutex lock/unlock에 대해 예외 처리를 해야할까?
void	pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_mutex[0]);
	philo_print(philo, "has taken a fork");
	*(philo->fork[0]) = 1;
	pthread_mutex_lock(philo->fork_mutex[1]);
	philo_print(philo, "has taken a fork");
	*(philo->fork[1]) = 1;
}

void	put_down_forks(t_philo *philo)
{
	*(philo->fork[1]) = 0;
	pthread_mutex_unlock(philo->fork_mutex[1]);
	*(philo->fork[0]) = 0;
	pthread_mutex_unlock(philo->fork_mutex[0]);
}

void	eating(t_philo *philo)
{
	philo->philo_last_eat = get_current_time();
	philo->philo_count_eat++;
	philo_print(philo, "is eating");
	philo_sleep(philo->shared->param.philo_time_eat);
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
