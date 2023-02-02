/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:13:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/02/02 15:08:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	execute_command(char *argv, char **envp)
{
	char	*command;
	char	*path;
	char	**tokens;
	int		i;

	tokens = ft_split(argv, ' ');
	command = ft_strjoin("/", tokens[0]);
	if (tokens == NULL || command == NULL)
		return (-1);
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

void	child_write(char **argv, char **envp, int *pfd)
{
	int	infile;

	if (access(argv[1], F_OK) == -1)
		px_error("No such file or directory\n", argv[1], 0);
	infile = px_open(argv[1], O_RDONLY);
	px_close(pfd[READ_END]);
	if (pfd[WRITE_END] != STDOUT_FILENO)
	{
		px_dup2(pfd[WRITE_END], STDOUT_FILENO);
		px_close(pfd[WRITE_END]);
		px_dup2(infile, STDIN_FILENO);
		px_close(infile);
	}
	if (execute_command(argv[2], envp) == -1)
		px_error("command not found\n", argv[2], 0);
}

void	child_read(char **argv, char **envp, int *pfd)
{
	int	outfile;

	outfile = px_open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	px_close(pfd[WRITE_END]);
	if (pfd[READ_END] != STDIN_FILENO)
	{
		px_dup2(pfd[READ_END], STDIN_FILENO);
		px_close(pfd[READ_END]);
		px_dup2(outfile, STDOUT_FILENO);
		px_close(outfile);
	}
	if (execute_command(argv[3], envp) == -1)
		px_error("command not found\n", argv[3], 127);
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		status;
	pid_t	pid[2];

	if (argc != 5)
		px_error("Usage: ./pipex infile \"command1\" \"command2\" " \
				"outfile\n", NULL, 1);
	px_pipe(pfd);
	pid[0] = fork();
	if (pid[0] == -1)
		px_error("Error: fork\n", NULL, 1);
	else if (pid[0] == 0)
		child_write(argv, envp, pfd);
	pid[1] = fork();
	if (pid[1] == -1)
		px_error("Error: fork\n", NULL, 1);
	else if (pid[1] == 0)
		child_read(argv, envp, pfd);
	px_close(pfd[0]);
	px_close(pfd[1]);
	if (waitpid(pid[0], NULL, WNOHANG) == -1)
		px_error("Error: child write\n", NULL, 1);
	if (waitpid(pid[1], &status, 0) == -1)
		px_error("Error: child read\n", NULL, 1);
	return (WEXITSTATUS(status));
}
