/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_libf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:58:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 21:15:34 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
