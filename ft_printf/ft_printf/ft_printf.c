/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:11:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/10 18:39:40 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(va_list *ap, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (spec == 's')
		return (print_string(va_arg(*ap, char *)));
	else if (spec == 'p')
		return (print_address(va_arg(*ap, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_number(va_arg(*ap, int), "0123456789", 1));
	else if (spec == 'u')
		return (print_number(va_arg(*ap, unsigned int), "0123456789", 0));
	else if (spec == 'x')
		return (print_number(va_arg(*ap, unsigned int), "0123456789abcdef", 0));
	else if (spec == 'X')
		return (print_number(va_arg(*ap, unsigned int), "0123456789ABCDEF", 0));
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
	int		printed;

	va_start(ap, format);
	printed = parsing_format(format, &ap);
	va_end(ap);
	if (printed < 0)
		return (-1);
	return (printed);
}
