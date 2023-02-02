/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:35 by gychoi            #+#    #+#             */
/*   Updated: 2023/02/02 17:58:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipeline_child(char *command, char **envp)
{
	int		pfd[2];
	pid_t	pid;

	if (pipe(pfd) == -1)
		px_error("Error: pipe\n", NULL, 1);
	pid = fork();
	if (pid == -1)
		px_error("Error: fork\n", NULL, 1);
	else if (pid == 0)
	{
		if (close(pfd[READ_END]) == -1)
			px_error("Error: close\n", NULL, 1);
		px_dup2(pfd[WRITE_END], STDOUT_FILENO);
		if (execute_command(command, envp) == -1)
			px_error("command not found\n", command, 127);
	}
	else
	{
		if (waitpid(pid, NULL, WNOHANG) == -1)
			px_error("Error: wait child\n", NULL, 1);
		if (close(pfd[WRITE_END]) == -1)
			px_error("Error: close\n", NULL, 1);
		px_dup2(pfd[READ_END], STDIN_FILENO);
	}
}

void	pipeline(int argc, char **argv, char **envp, int i)
{
	int	infile;
	int	outfile;

	if (access(argv[1], F_OK) == -1)
		px_error("No such file or directory\n", argv[1], 0);
	infile = px_open(argv[1], O_RDONLY);
	outfile = px_open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	px_dup2(infile, STDIN_FILENO);
	px_dup2(outfile, STDOUT_FILENO);
	while (i < argc - 2)
		pipeline_child(argv[i++], envp);
	if (execute_command(argv[argc - 2], envp) == -1)
		px_error("command not found\n", argv[argc - 2], 127);
}

// LIMITER strcmp (LIMITER, LIMITERR) 부분 해결할 것!
// unset 부분도 가능하면 확인해보기.
void	read_line(int *pfd, char *limiter)
{
	char	*line;

	if (close(pfd[READ_END]) == -1)
		px_error("Error: close\n", NULL, 1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			exit(0);
		if (write(pfd[WRITE_END], line, ft_strlen(line)) == -1)
			px_error("Error: write\n", NULL, 1);
		free(line);
	}
}

void	here_doc(int argc, char **argv, char **envp, int i)
{
	int		outfile;
	int		pfd[2];
	pid_t	pid;

	if (pipe(pfd) == -1)
		px_error("Error: pipe\n", NULL, 1);
	pid = fork();
	if (pid == -1)
		px_error("Error: fork\n", NULL, 1);
	else if (pid == 0)
		read_line(pfd, argv[2]);
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
			px_error("Error: wait child\n", NULL, 1);
		if (close(pfd[WRITE_END]) == -1)
			px_error("Error: close\n", NULL, 1);
		px_dup2(pfd[READ_END], STDIN_FILENO);
	}
	outfile = px_open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND);
	px_dup2(outfile, STDOUT_FILENO);
	while (i < argc - 2)
		pipeline_child(argv[i++], envp);
	if (execute_command(argv[argc - 2], envp) == -1)
		px_error("command not found\n", argv[argc - 2], 127);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	int		i;
	pid_t	pid;

	if (argc < 5)
		return (1);
	pid = fork();
	if (pid == -1)
		px_error("Error: fork\n", NULL, 1);
	else if (pid == 0)
	{
		i = 2;
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			here_doc(argc, argv, envp, i + 1);
		else
			pipeline(argc, argv, envp, i);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			px_error("Error: wait child\n", NULL, 1);
	}
	return (WEXITSTATUS(status));
}
