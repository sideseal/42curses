/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:48:44 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/12 18:14:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_quotient(int n)
{
	int	q;

	q = 1;
	if (n < 0)
		q *= -1;
	if (-9 <= n && n <= 9)
		return (q);
	q *= 10;
	while (n / q >= 10)
		q *= 10;
	return (q);
}

static size_t	get_length(int q)
{
	size_t	c;

	c = 1;
	if (q < 0)
		c++;
	while (q / 10 != 0)
	{
		c++;
		q /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		q;
	size_t	len;
	size_t	start;
	char	*arr;

	q = find_quotient(n);
	len = get_length(q);
	arr = malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	start = 0;
	if (n < 0)
	{
		arr[start] = '-';
		start++;
	}
	while (start < len)
	{
		arr[start] = (n / q) + '0';
		start++;
		n = n % q;
		q /= 10;
	}
	arr[start] = '\0';
	return (arr);
}
