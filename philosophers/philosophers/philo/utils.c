/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:25:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/19 23:46:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_dead(t_philo *philo)
{
	int			timestamp;
	long long	curr;

	pthread_mutex_lock(&(philo->share->share_lock));
	if (philo->share->stop)
	{
		pthread_mutex_unlock(&(philo->share->share_lock));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->share->share_lock));
	curr = get_current_time();
	if (curr - philo->philo_time_last_eat > philo->share->args.philo_time_die)
	{
		pthread_mutex_lock(&(philo->share->share_lock));
		curr = get_current_time();
		timestamp = (int)(curr - philo->share->philo_start_time);
		if (!philo->share->stop)
			printf("%d %d died\n", timestamp, philo->philo_id);
		philo->share->stop = 1;
		pthread_mutex_unlock(&(philo->share->share_lock));
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

int	atoi_only_unsigned(char *n)
{
	int			i;
	int			mark;
	long long	value;

	i = 0;
	mark = 0;
	while (n[i] != '\0')
	{
		if (!(n[i] == '+' || ('0' <= n[i] && n[i] <= '9')) || mark > 1)
			return (-1);
		if (n[i] == '+')
			mark++;
		i++;
	}
	i = mark;
	mark = 0;
	value = 0;
	while (('0' <= n[i] && n[i] <= '9') && n[i] != '\0')
	{
		value = value * 10 + (n[i++] - '0');
		mark++;
	}
	if (!mark || n[i] != '\0' || value > 2147483647)
		return (-1);
	return ((unsigned int)value);
}

int	valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != 0)
	{
		if (atoi_only_unsigned(argv[i]) <= 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
