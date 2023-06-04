/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:58:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 22:50:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_atof(const char *str, int *error)
{
	size_t	i;
	double	ret;
	int		precision;

	ret = rt_atoi(str, error);
	if (*error)
		return (*error);
	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] == 0)
		return (ret);
	if (str[i + 1] == 0)
		return (*error);
	if (ret > 0)
		ret += tollp(str, i + 1, &precision, error) * pow(10, -1 * precision);
	else
		ret -= tollp(str, i + 1, &precision, error) * pow(10, -1 * precision);
	return (ret);
}

int	rt_atoi(const char *str, int *error)
{
	size_t		idx;
	long long	ret;
	int			sign;

	idx = 0;
	sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		++idx;
	}
	if (str[idx] == '.')
	{
		*error = 1;
		return (*error);
	}
	ret = toll(str, sign, idx, error);
	if (str[idx] == 0 || ret > INT_MAX || ret < INT_MIN)
		*error = 1;
	return ((int)ret);
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
