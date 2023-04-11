/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:41:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/11 23:20:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_millisecond(void)
{
	struct timeval	time;
	long long		millisecond;

	gettimeofday(&time, 0);
	millisecond = time.tv_sec * (long long)1000 + time.tv_usec / 1000;
	return (millisecond);
}

int	philo_abort(char *string)
{
	printf("%s\n", string);
	return (1);
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
