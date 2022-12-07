/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:08:50 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:40:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(char *a)
{
	int			i;
	int			sign;
	int			digit_flag;
	long long	value;

	i = 0;
	sign = 1;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i++] == '-')
			sign *= -1;
	}
	value = 0;
	digit_flag = 0;
	while (('0' <= a[i] && a[i] <= '9') && a[i] != '\0')
	{
		value = value * 10 + sign * (a[i++] - '0');
		if (2147483647 < value || value < -2147483648)
			ps_error();
		digit_flag = 1;
	}
	if (!digit_flag || a[i] != '\0')
		ps_error();
	return ((int)value);
}

static void	fill_array(int *array, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		array[i] = ps_atoi(argv[i + 1]);
		i++;
	}
}

static void	check_duplicate(int *array, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (array[i] == array[j])
				ps_error();
			j++;
		}
		i++;
	}
}

int	*get_valid_param(int argc, char **argv)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		exit(1);
	fill_array(array, argc, argv);
	check_duplicate(array, argc);
	return (array);
}
