/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:32:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/19 15:14:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../project/get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*ret1;
	char	*ret2;

	fd1 = open("./test/test1.txt", O_RDONLY);
	fd2 = open("./test/test2.txt", O_RDONLY);
	printf("GNL START =========>\n");
	ret1 = get_next_line(fd1);
	while (ret1)
	{
		printf("fd1 return: %s\n", ret1);
		ret1 = get_next_line(fd1);
	}
	ret2 = get_next_line(fd2);
	while (ret2)
	{
		printf("fd2 return: %s\n", ret2);
		ret2 = get_next_line(fd2);
	}
	printf("<=============== END\n");
	close(fd1);
	close(fd2);
	return (0);
}
