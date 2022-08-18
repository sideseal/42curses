/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:32:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/18 16:25:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../project/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*ret;

	fd = open("./test/test.txt", O_RDONLY);
	printf("GNL START =========>\n");
	ret = get_next_line(fd);
	while (ret)
	{
		printf("return: %s\n", ret);
		ret = get_next_line(fd);
	}
	printf("<=============== END\n");
	return (0);
}
