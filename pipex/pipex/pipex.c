/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:13:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/16 00:38:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		px_error("Usage: ./pipex infile cmd1 | cmd2 outfile\n", 2);
	if (pipe(fd) < 0)
		px_error("Error: pipe\n");
	pid = fork();
	if (pid < 0)
		px_error("Error: fork\n");
	else if (pid == 0)
		child(argv, envp, fd);
	// wait
	// parent
	// envp의 PATH 찾아서 명령어 실행
	// 파일 실행
	return (0);
}
