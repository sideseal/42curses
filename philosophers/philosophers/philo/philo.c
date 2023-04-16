/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/17 00:36:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	int	timestamp;

	timestamp = (int)(get_current_time() - philo->shared->start_time);
	pthread_mutex_lock(&(philo->shared->shared_mutex));
	if (!philo->shared->philo_is_dead)
		printf("%d %d %s\n", timestamp, philo->philo_name, str);
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
}

void	philo_sleep(long long wait_time)
{
	long long	sleep_start;
	long long	sleep_total;

	sleep_start = get_current_time();
	sleep_total = wait_time + sleep_start;
	usleep(wait_time * 0.9);
	while (get_current_time() < sleep_total)
		usleep(500);
}

int	philo_dead(t_philo *philo)
{
	int	dead;
	int	timestamp;

	if (get_current_time() - philo->philo_last_eat > philo->shared->param.philo_time_die)
	{
		pthread_mutex_lock(&(philo->shared->shared_mutex));
		timestamp = (int)(get_current_time() - philo->shared->start_time);
		if (!philo->shared->philo_is_dead)
			printf("%d %d dead\n", timestamp, philo->philo_name);
		philo->shared->philo_is_dead = 1;
		pthread_mutex_unlock(&(philo->shared->shared_mutex));
		return (1);
	}
	pthread_mutex_lock(&(philo->shared->shared_mutex));
	dead = philo->shared->philo_is_dead;
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
	return (dead);
}
