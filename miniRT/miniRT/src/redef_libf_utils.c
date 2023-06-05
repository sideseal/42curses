/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:06:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 16:57:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_atoi(const char *str, int *error, int *sign)
{
	size_t		idx;
	long long	ret;

	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			*sign = -1;
		++idx;
	}
	ret = toll(str, *sign, idx, error);
	if (str[idx] == 0 || ret > INT_MAX || ret < INT_MIN)
		*error = TRUE;
	return ((int)ret);
}

long long	toll(const char *str, int sign, size_t idx, int *error)
{
	long long	acc;
	long long	llmax;

	acc = 0;
	llmax = LONG_LONG_MAX;
	while (str[idx] && str[idx] != '.')
	{
		if (ft_isdigit(str[idx]) == FALSE)
		{
			*error = TRUE;
			return (*error);
		}
		if ((acc > llmax / 10) \
			|| ((acc == llmax / 10 && (str[idx] - '0') > (llmax % 10))) \
			|| !ft_isdigit(str[idx]))
		{
			if (sign == 1)
				return (llmax);
			else
				return (-llmax - 1LL);
		}
		acc = acc * 10 + str[idx] - '0';
		++idx;
	}
	return (sign * acc);
}

long long	tollp(const char *str, size_t idx, int *precision, int *error)
{
	long long		acc;
	long long		llmax;

	acc = 0;
	*precision = 0;
	llmax = LONG_LONG_MAX;
	while (str[idx])
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[idx] - '0' \
		> (llmax % 10)) || !ft_isdigit(str[idx]) || *precision >= 15)
		{
			*error = TRUE;
			return (*error);
		}
		acc = acc * 10 + str[idx] - '0';
		++*precision;
		++idx;
	}
	return (acc);
}
