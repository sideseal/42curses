/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:11:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/09 23:01:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // 지우기

int	handle_specifier(va_list *ap, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (spec == 's')
		return (print_string(va_arg(*ap, char *)));
	else if (spec == 'p')
		return (print_address(va_arg(*ap, void *)));
	else if (spec == 'd' || spec == 'i')
		// ft_itoa
		;
	else if (spec == 'u')
		// print unsigned
		;
	else if (spec == 'x')
		// print hex low
		;
	else if (spec == 'X')
		// print hex upper
		;
	else if (spec == '%')
		return (print_char('%'));
	else
		return (-1);
}

int	parsing_format(const char *format, va_list *ap)
{
	int	ret;
	int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ret = handle_specifier(ap, *(++format));
			if (ret < 0)
				return (-1);
		}
		else
		{
			ret = (int)write(1, &(*format), 1);
			if (ret < 0)
				return (-1);
		}
		printed += ret;
		format++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	printed;

	va_start(ap, format);
	printed = parsing_format(format, &ap);
	va_end(ap);
	if (printed < 0)
		return (-1);
	return (printed);
}

int	main(void)
{
	int	len1;
	int	len2;
	int	len3;
	char	p[] = "hello\n";

	len1 = ft_printf("hell%c, %s", 'O', "world");
	printf("len: %d\n", len1);
	len2 = ft_printf("%s", NULL);
	printf("len: %d\n", len2);
	len3 = ft_printf("%p", p);
	printf("len: %d\n", len3);
	return (0);
}
