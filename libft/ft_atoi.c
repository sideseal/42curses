/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:42 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/16 13:43:02 by gychoi           ###   ########.fr       */
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
	unsigned long long	v;
	unsigned long long	t;

	i = 0;
	sign = 1;
	v = 0;
	while (is_space(str, i))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
	{
		v = v * 10 + (str[i++] - '0');
		if (sign < 0 && (v > 9223372036854775807 || (i > 19 && v < t)))
			return (0);
		if (v > 9223372036854775807 || (i > 18 && v < t))
			return (-1);
		t = v;
	}
	return ((int)(v * sign));
}
