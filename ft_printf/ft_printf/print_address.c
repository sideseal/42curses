/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:42:55 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/10 18:37:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address_recursive(unsigned long long num, char *base)
{
	int	printed;
	int	ret;

	printed = 0;
	if (num >= 16)
		printed += print_address_recursive(num / 16, base);
	ret = (int)write(1, &base[num % 16], 1);
	if (ret < 0)
		return (-1);
	printed += ret;
	return (printed);
}

int	print_address(void *p)
{
	unsigned long long	daddr;
	int					printed;
	int					ret;

	if (p == 0)
	{
		ret = (int)write(1, "0x0", 3);
		if (ret < 0)
			return (-1);
		return (ret);
	}
	printed = 0;
	daddr = (unsigned long long)p;
	ret = (int)write(1, "0x", 2);
	if (ret < 0)
		return (-1);
	printed += ret;
	ret = print_address_recursive(daddr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	printed += ret;
	return (printed);
}
