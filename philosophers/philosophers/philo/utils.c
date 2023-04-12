/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:41:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/12 23:50:28 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	time;
	long long		millisecond;

	if (gettimeofday(&time, 0) < 0)
		return (-1);
	millisecond = time.tv_sec * (long long)1000 + time.tv_usec / 1000;
	return (millisecond);
}

void	philo_print(t_philo *philo, char *str)
{
	int	timestamp;

	timestamp = (int)(get_current_time() - philo->shared->start_time);
	pthread_mutex_lock(&(philo->shared->shared_mutex));
	printf("%d %d %s\n", timestamp, philo->philo_name, str);
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
}

void	philo_sleep(long long wait_time)
{
	long long	sleep_start;

	sleep_start = get_current_time();
	while (get_current_time() - sleep_start < wait_time)
		usleep(10);
}

int	philo_atoi(char *num)
{
	int			i;
	int			flag;
	long long	value;

	i = -1;
	flag = 0;
	while (num[++i] != '\0')
	{
		if (!(num[i] == '+' || ('0' <= num[i] && num[i] <= '9')) || flag > 1)
			return (-1);
		if (num[i] == '+')
			flag++;
	}
	i = flag;
	value = 0;
	flag = 0;
	while (('0' <= num[i] && num[i] <= '9') && num[i] != '\0')
	{
		value = value * 10 + (num[i++] - '0');
		flag = 1;
	}
	if (!flag || num[i] != '\0' || (2147483647 < value || value < -2147483648))
		return (-1);
	return ((int)value);
}

int	check_valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != 0)
	{
		if (philo_atoi(argv[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}
