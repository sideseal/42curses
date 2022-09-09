/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:08:49 by gychoi            #+#    #+#             */
/*   Updated: 2022/09/09 21:12:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	print_char(char c)
{
	ssize_t	ret;

	ret = (int)write(1, &c, 1);
	if (ret < 0)
		return (-1);
	return (ret);
}
