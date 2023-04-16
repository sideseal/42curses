/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:41:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/16 23:32:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	time_val;
	long long		millisecond;

	if (gettimeofday(&time_val, 0) < 0)
		return (-1);
	millisecond = time_val.tv_sec * (long long)1000 + time_val.tv_usec / 1000;
	return (millisecond);
}

int	atoi_only_unsigned(char *num)
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
		if (atoi_only_unsigned(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
