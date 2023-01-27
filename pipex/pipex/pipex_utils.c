/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:22:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/27 00:03:19 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_error(char *str, char *file)
{
	if (file)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
	}
	else
		ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

int	px_open(char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == -1)
		px_error("Error: open\n", filename);
	return (fd);
}

void	px_close(int fd)
{
	if (close(fd) == -1)
		px_error("Error: close\n", NULL);
}

void	px_pipe(int *fd)
{
	if (pipe(fd) == -1)
		px_error("Error: pipe\n", NULL);
}

void	px_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
			px_error("Error: dup2\n", NULL);
}
