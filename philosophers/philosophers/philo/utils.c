/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:25:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 19:05:34 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	int	timestamp;

	pthread_mutex_lock(&(philo->share->share_lock));
	timestamp = (int)(get_current_time() - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(&(philo->share->share_lock));
}

int	philo_sleep(long long wait_time, t_philo *philo)
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

void	philo_dead(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&(philo->share->share_lock));
	timestamp = (int)(get_current_time() - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d died\n", timestamp, philo->philo_id);
	philo->share->stop = TRUE;
	pthread_mutex_unlock(&(philo->share->share_lock));
}

int	check_philo_dead(t_philo *philo)
{
	int			stop;
	long long	last_eat;

	pthread_mutex_lock(&(philo->share->share_lock));
	stop = philo->share->stop;
	pthread_mutex_unlock(&(philo->share->share_lock));
	if (stop == TRUE)
		return (TRUE);
	last_eat = philo->philo_time_last_eat;
	if (get_current_time() - last_eat > philo->share->args.philo_time_die)
	{
		philo_dead(philo);
		return (TRUE);
	}
	return (FALSE);
}

long long	get_current_time(void)
{
	struct timeval	time_val;
	long long		millisecond;

	gettimeofday(&time_val, 0);
	millisecond = time_val.tv_sec * 1000LL + time_val.tv_usec / 1000LL;
	return (millisecond);
}
