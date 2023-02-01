/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/02/02 01:38:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# include "../libft/libft.h"

# define READ_END	0
# define WRITE_END	1

char	*find_path(char *command, char **envp);
int		execute_command(char *argv, char **envp);
void	px_error(char *str, char *file, int exitcode);
int		px_open(char *filename, int flags);
void	px_dup2(int fd1, int fd2);

#endif
