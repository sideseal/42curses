/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:42 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/12 21:22:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (is_space(str, i))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (sign < 0 && value > 9223372036854775807)
		return (0);
	if (value > 9223372036854775807)
		return (-1);
	return ((int)(value * sign));
}
