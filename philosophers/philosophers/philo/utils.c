/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:25:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 21:42:40 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	int	timestamp;

	lock(&(philo->share->share_lock), philo);
	timestamp = (int)(get_current_time(philo) - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d %s\n", timestamp, philo->philo_id, str);
	unlock(&(philo->share->share_lock), philo);
}

int	philo_sleep(long long wait_time, t_philo *philo)
{
	long long	sleep_start;
	long long	sleep_total;

	sleep_start = get_current_time(philo);
	sleep_total = wait_time + sleep_start;
	while (get_current_time(philo) < sleep_total)
	{
		if (check_philo_dead(philo) == TRUE)
			return (FALSE);
		if (usleep(500) < 0)
		{
			philo->error = TRUE;
			return (FALSE);
		}
	}
	return (TRUE);
}

void	philo_dead(t_philo *philo)
{
	int	timestamp;

	lock(&(philo->share->share_lock), philo);
	timestamp = (int)(get_current_time(philo) - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d died\n", timestamp, philo->philo_id);
	philo->share->stop = TRUE;
	unlock(&(philo->share->share_lock), philo);
}

int	check_philo_dead(t_philo *philo)
{
	int			stop;
	long long	last_eat;
	long long	time_die;

	lock(&(philo->share->share_lock), philo);
	stop = philo->share->stop;
	unlock(&(philo->share->share_lock), philo);
	if (stop == TRUE)
		return (TRUE);
	last_eat = philo->philo_time_last_eat;
	time_die = philo->share->args.philo_time_die;
	if (get_current_time(philo) - last_eat > time_die)
	{
		philo_dead(philo);
		return (TRUE);
	}
	return (FALSE);
}

long long	get_current_time(t_philo *philo)
{
	struct timeval	time_val;
	long long		millisecond;

	if (gettimeofday(&time_val, 0) < 0)
	{
		if (philo != 0)
			philo->error = TRUE;
	}
	millisecond = time_val.tv_sec * 1000LL + time_val.tv_usec / 1000LL;
	return (millisecond);
}
