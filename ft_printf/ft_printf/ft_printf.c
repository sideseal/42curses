/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:11:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/08 16:41:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "stdio.h" // just for test

int	parsing_format(va_list *ap, char type)
{
// 	if (type == 'c')
// 		// ft_write
// 	if (type == 's')
// 		// ft_write with sentence len
// 		;
// 	if (type == 'p')
// 		// print_memory
// 		;
// 	if (type == 'd' || type == 'i')
// 		// ft_itoa
// 		;
// 	if (type == 'u')
// 		// print unsigned
// 		;
// 	if (type == 'x')
// 		// print hex low
// 		;
// 	if (type == 'X')
// 		// print hex upper
// 		;
// 	if (type == '%')
// 		// print %
// 		;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len += parsing_format(&ap, format[i + 1]);
			i++;
			continue ;
		}
		// write one character format[i]
		len++;
		i++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	ft_printf("hello%d\n", 10);
	return (0);
}
