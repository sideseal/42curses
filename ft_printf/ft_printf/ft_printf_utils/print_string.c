/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:05:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/09 23:17:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	print_string(char *str)
{
	int	printed;
	int	len;

	if (str == NULL)
	{
		printed = (int)write(1, "(null)", 6);
		if (printed < 0)
			return (-1);
		return (printed);
	}
	len = 0;
	while (str[len] != 0)
		len++;
	printed = (int)write(1, str, len);
	if (printed < 0)
		return (-1);
	return (printed);
}
