/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:43:19 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/10 18:39:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	printed;

	if (num == -2147483648)
	{
		if ((int)write(1, "-2147483648", 11) < 0)
			return (-1);
		return (11);
	}
	printed = 0;
	if (num < 0)
	{
		if ((int)write(1, "-", 1) < 0)
			return (-1);
		printed++;
		num *= -1;
	}
	if (num >= 10)
		printed += ft_putnbr(num / 10);
	num = (num % 10) + '0';
	if ((int)write(1, &num, 1) < 0)
		return (-1);
	printed++;
	return (printed);
}

unsigned int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	print_number_recursive(unsigned int num, char *base)
{
	int				printed;
	unsigned int	blen;
	int				ret;

	blen = base_len(base);
	printed = 0;
	if (num >= blen)
		printed += print_number_recursive(num / blen, base);
	ret = (int)write(1, &base[num % blen], 1);
	if (ret < 0)
		return (-1);
	printed += ret;
	return (printed);
}

int	print_number(int num, char *base, int sign)
{
	int	printed;

	if (sign)
		printed = ft_putnbr(num);
	else
		printed = print_number_recursive((unsigned int)num, base);
	if (printed < 0)
		return (-1);
	return (printed);
}
