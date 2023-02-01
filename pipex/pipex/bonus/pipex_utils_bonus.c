/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:43 by gychoi            #+#    #+#             */
/*   Updated: 2023/02/02 01:37:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char *command, char **envp)
{
	int		i;
	char	*path;
	char	*find;
	char	**paths;

	if (access(command, F_OK | X_OK) == 0)
		return (command);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	find = NULL;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], command);
		if (access(path, F_OK | X_OK) == 0)
			find = ft_strdup(path);
		free(paths[i]);
		free(path);
		i++;
	}
	free(paths);
	return (find);
}

// split, strjoin NULL 처리 해줘야 할까?
int	execute_command(char *argv, char **envp)
{
	char	*command;
	char	*path;
	char	**tokens;
	int		i;

	tokens = ft_split(argv, ' ');
	command = ft_strjoin("/", tokens[0]);
	path = find_path(command, envp);
	if (execve(path, tokens, envp) == -1)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
		free(command);
		free(path);
	}
	return (-1);
}

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

	if (flags == (O_WRONLY | O_CREAT | O_TRUNC) \
		|| flags == (O_WRONLY | O_CREAT | O_APPEND))
		fd = open(filename, flags, 0644);
	else
		fd = open(filename, flags);
	if (fd == -1)
		px_error("Error: open\n", filename, 126);
	return (fd);
}

void	px_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		px_error("Error: dup2\n", NULL, 1);
	if (close(fd1) == -1)
		px_error("Error: close\n", NULL, 1);
}
