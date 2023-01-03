/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:52:46 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/31 23:17:22 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *str)
{
	perror(str);
	exit(1);
}

int	fdf_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	fdf_open(char *path, int flag)
{
	int	fd;

	fd = open(path, flag);
	if (fd < 0)
		fdf_error("Error: file open ");
	return (fd);
}

void	fdf_close(int fd)
{
	if (close(fd) < 0)
		fdf_error("Error: file close ");
}

void	*fdf_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		fdf_error("Error: malloc ");
	return (ret);
}
