/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:33:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/10/31 23:47:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

int	check_num(const char *str)
{
	int		i;
	int		sign;
	int		is_digit;
	long long	value;

	i = 0;
	sign = 1;
	is_digit = 0;
	value = 0;
	while (is_space(str, i))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
	{
		value = value * 10 + (str[i++] - '0');
		is_digit = 1;
	}
	if (2147483647 < value * sign || value * sign < -2147483648 || !is_digit)
		ft_error();
	return (value * sign);
}
