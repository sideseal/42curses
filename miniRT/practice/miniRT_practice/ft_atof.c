/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:09 by salee2            #+#    #+#             */
/*   Updated: 2022/09/23 16:19:12 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

long long	tollp(const char *str, size_t i, int *precision)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0;
	*precision = 0;
	while (str[i])
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[i] - '0' \
		> (llmax % 10)) || !ft_isdigit(str[i]) || *precision >= 15)
			exit(EXIT_FAILURE);
		acc = acc * 10 + str[i] - '0';
		++*precision;
		++i;
	}
	return (acc);
}

double	ft_atof(const char *str)
{
	size_t	i;
	double	ret;
	double	sign;
	int		precision;
	t_bool	is_error;

	is_error = 0;
	ret = ft_atoi(str, &is_error, &sign);
	if (is_error)
		exit(EXIT_FAILURE);
	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == 0)
		return (ret);
	if (str[i + 1] == 0)
		exit(EXIT_FAILURE);
	if (sign == 1)
		ret = ret + tollp(str, i + 1, &precision) * pow(10, -1 * precision);
	else
		ret = ret - tollp(str, i + 1, &precision) * pow(10, -1 * precision);
	return (ret);
}
