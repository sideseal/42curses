/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:06:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 17:07:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
