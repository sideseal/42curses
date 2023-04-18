/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:25:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/18 21:20:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *str)
{
	int			timestamp;
	long long	current_time;

	pthread_mutex_lock(&(philo->share->share_lock));
	current_time = get_current_time();
	if (current_time < 0)
		philo->share->stop = 1;
	timestamp = (int)(current_time - philo->share->philo_start_time);
	if (!philo->share->stop)
		printf("%d %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(&(philo->share->share_lock));
}

void	philo_sleep(long long wait_time, t_philo *philo)
{
	long long	sleep_start;
	long long	sleep_total;

	sleep_start = get_current_time();
	sleep_total = wait_time + sleep_start;
	usleep(wait_time * 0.7);
	while (get_current_time() < sleep_total)
	{
		if (philo->share->stop)
			break ;
		usleep(500);
	}
}

long long	get_current_time(void)
{
	struct timeval	time_val;
	long long		millisecond;

	if (gettimeofday(&time_val, 0) < 0)
		return (-1);
	millisecond = time_val.tv_sec * (long long)1000 + time_val.tv_usec / 1000;
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
		if (atoi_only_unsigned(argv[i]) < 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
