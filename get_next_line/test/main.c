/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:32:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/24 17:12:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

void	check_leak(void)
{
//	system("export MallocStackLogging=1");
	system("leaks --list -- app.out");
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*ret1;
	char	*ret2;
	char	*ret3;
	char	*ret4;

	fd1 = open("./test/test1.txt", O_RDONLY);
	fd2 = open("./test/test2.txt", O_RDONLY);
	fd3 = open("./test/test3.txt", O_RDONLY);
	fd4 = open("./test/test4.txt", O_RDONLY);
	printf("GNL START =========>\n");
	printf("\n***** TEST 1 *****\n");
	ret1 = get_next_line(fd1);
	while (ret1)
	{
		printf("* fd1 return: %s\n", ret1);
		printf("-----------------\n");
		free(ret1);
		ret1 = get_next_line(fd1);
	}
	printf("\n***** TEST 2 *****\n");
	ret2 = get_next_line(fd2);
	while (ret2)
	{
		printf("* fd2 return: %s\n", ret2);
		printf("-----------------\n");
		free(ret2);
		ret2 = get_next_line(fd2);
	}
	printf("\n***** TEST 3 *****\n");
	ret3 = get_next_line(fd3);
	ret4 = get_next_line(fd4);
	while (ret4)
	{
		printf("* fd3 return: %s\n", ret3);
		printf("* fd4 return: %s\n", ret4);
		printf("-----------------\n");
		free(ret3);
		free(ret4);
		ret3 = get_next_line(fd3);
		ret4 = get_next_line(fd4);
	}
	printf("<=============== END\n");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	atexit(check_leak);
	return (0);
}
