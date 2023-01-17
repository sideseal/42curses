/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:13:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/18 02:14:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*set_path(char *command, char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], command);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

int	execute_command(char *argv, char **envp)
{
	char	*command;
	char	*path;
	char	**tokens;
	int		i;

	tokens = ft_split(argv, ' ');
	command = ft_strjoin("/", tokens[0]);
	path = set_path(command, envp);
	free(command);
	if (execve(path, tokens, envp) == -1)
	{
		i = -1;
		while (tokens[++i])
			free(tokens[i]);
		free(tokens);
		free(path);
	}
	return (-1);
}

void	child_write(char **argv, char **envp, int *pfd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		px_error(argv[1], "No such file or directory\n");
	if (close(pfd[READ_END]) == -1)
		px_error(NULL, "Error: close\n");
	if (pfd[WRITE_END] != STDOUT_FILENO)
	{
		if (dup2(pfd[WRITE_END], STDOUT_FILENO) == -1)
			px_error(NULL, "Error: dup2\n");
		if (close(pfd[WRITE_END]) == -1)
			px_error(NULL, "Error: close\n");
		if (dup2(infile, STDIN_FILENO) == -1)
			px_error(NULL, "Error: dup2\n");
		if (close(infile) == -1)
			px_error(NULL, "Error: close\n");
	}
	if (execute_command(argv[2], envp) == -1)
		px_error(argv[2], "command not found\n");
}

void	child_read(char **argv, char **envp, int *pfd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		px_error(argv[4], "Error: open\n");
	if (close(pfd[WRITE_END]) == -1)
		px_error(NULL, "Error: close\n");
	if (pfd[READ_END] != STDIN_FILENO)
	{
		if (dup2(pfd[READ_END], STDIN_FILENO) == -1)
			px_error(NULL, "Error: dup2\n");
		if (close(pfd[READ_END]) == -1)
			px_error(NULL, "Error: close\n");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			px_error(NULL, "Error: dup2\n");
		if (close(outfile) == -1)
			px_error(NULL, "Error: close\n");
	}
	if (execute_command(argv[3], envp) == -1)
		px_error(argv[3], "command not found\n");
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	pid_t	pid[2];

	if (argc != 5)
		px_error(NULL, "Usage: ./pipex infile \"command1\" \"command2\" outfile\n");
	if (pipe(pfd) == -1)
		px_error(NULL, "Error: pipe\n");
	pid[0] = fork();
	if (pid[0] == -1)
		px_error(NULL, "Error: fork\n");
	if (pid[0] == 0)
		child_write(argv, envp, pfd);
	pid[1] = fork();
	if (pid[1] == -1)
		px_error(NULL, "Error: fork\n");
	if (pid[1] == 0)
		child_read(argv, envp, pfd);
	if (close(pfd[0]) == -1)
		px_error(NULL, "Error: close\n");
	if (close(pfd[1]) == -1)
		px_error(NULL, "Error: close\n");
	if (waitpid(pid[0], NULL, WNOHANG) == -1)
		px_error(NULL, "Error: waitpid\n");
	if (waitpid(pid[1], NULL, WNOHANG) == -1)
		px_error(NULL, "Error: waitpid\n");
	return (0);
}
