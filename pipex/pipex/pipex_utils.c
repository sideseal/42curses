/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:22:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/27 20:57:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_error(char *str, char *file, int exitcode)
{
	if (file)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
	}
	else
		ft_putstr_fd(str, STDERR_FILENO);
	exit(exitcode);
}

int	px_open(char *filename, int flags)
{
	int	fd;

	if (flags == (O_WRONLY | O_CREAT | O_TRUNC))
		fd = open(filename, flags, 0644);
	else
		fd = open(filename, flags);
	if (fd == -1)
		px_error("Error: open\n", filename, 126);
	return (fd);
}

void	px_close(int fd)
{
	if (close(fd) == -1)
		px_error("Error: close\n", NULL, 1);
}

void	px_pipe(int *fd)
{
	if (pipe(fd) == -1)
		px_error("Error: pipe\n", NULL, 1);
}

void	px_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		px_error("Error: dup2\n", NULL, 1);
}
