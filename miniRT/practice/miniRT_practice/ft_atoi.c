/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:24:41 by salee2            #+#    #+#             */
/*   Updated: 2022/08/01 13:24:52 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int	is_space(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

long long	toll(const char *str, long long sign, size_t i)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0;
	while (str[i] && str[i] != '.')
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[i] - '0' \
					> (llmax % 10)) || !ft_isdigit(str[i]))
		{
			if (sign == 1)
				return (LONG_LONG_MAX);
			else
				return (LONG_LONG_MIN);
		}
		acc = acc * 10 + str[i] - '0';
		++i;
	}
	return (sign * acc);
}

int	ft_atoi(const char *str, int *is_error, double *sign)
{
	size_t		i;
	long long	ret;

	i = 0;
	*sign = 1;
	while (is_space(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		++i;
	}
	ret = toll(str, *sign, i);
	if (str[i] == 0 || ret > INT_MAX || ret < INT_MIN)
		*is_error = 1;
	return ((int) ret);
}
