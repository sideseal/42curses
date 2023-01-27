/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:30:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/27 19:42:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# include "libft/libft.h"

# define READ_END	0
# define WRITE_END	1

void	px_error(char *file, char *str, int exitcode);
int		px_open(char *filename, int flags);
void	px_close(int fd);
void	px_dup2(int fd1, int fd2);
void	px_pipe(int *fd);

#endif
