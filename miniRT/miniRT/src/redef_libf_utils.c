/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:06:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 22:42:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

long long	toll(const char *str, long long sign, size_t idx, int *error)
{
	long long	acc;
	long long	llmax;

	acc = 0;
	llmax = LONG_LONG_MAX;
	while (str[idx] && str[idx] != '.')
	{
		if (ft_isdigit(str[idx]) == 0)
		{
			*error = 1;
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
			*error = 1;
			return (*error);
		}
		acc = acc * 10 + str[idx] - '0';
		++*precision;
		++idx;
	}
	return (acc);
}
