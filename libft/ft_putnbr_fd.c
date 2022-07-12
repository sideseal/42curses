/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:45:51 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/12 18:14:53 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putnbr_find_quotient(int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int	q;
	int	nb;

	if (n < 0)
		write(fd, "-", 1);
	q = putnbr_find_quotient(n);
	while (q)
	{
		nb = '0' + n / q;
		write(fd, &nb, 1);
		n %= q;
		q /= 10;
	}
}
