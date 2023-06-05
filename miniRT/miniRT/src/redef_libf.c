/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:58:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 22:32:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_atof(const char *str, int *error)
{
	size_t	i;
	double	ret;
	int		precision;
	int		sign;

	*error = FALSE;
	sign = 1;
	ret = rt_atoi(str, error, &sign);
	if (*error == TRUE)
		return (*error);
	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == 0 || (str[i] == '.' && str[i + 1] == 0))
		return (ret);
	if (sign > 0)
		ret += tollp(str, i + 1, &precision, error) * pow(10, -1 * precision);
	else
		ret -= tollp(str, i + 1, &precision, error) * pow(10, -1 * precision);
	return (ret);
}

void	rt_close(int fd, t_data *data)
{
	if (close(fd) < 0)
		print_error("close ", data);
	return ;
}

int	rt_open(char *file, int flag, t_data *data)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
		print_error("open ", data);
	return (fd);
}

void	*rt_malloc(size_t size, t_data *data)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		print_error("malloc ", data);
	return (ret);
}
