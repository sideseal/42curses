/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:05:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/09 23:00:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	print_string(char *str)
{
	ssize_t	ret;
	int	len;

	if (str == NULL)
	{
		ret = (int)write(1, "(null)", 6);
		if (ret < 0)
			return (-1);
		return (ret);
	}
	len = 0;
	while (str[len] != 0)
		len++;
	ret = (int)write(1, str, len);
	if (ret < 0)
		return (-1);
	return (ret);
}
