/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:58:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 22:26:47 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_line(t_data *data, char *line)
{
	char	**tokens;
	char	*info;

	tokens = ft_split(line, ' ');
	int	i;
	i = 0;
	while (tokens[i])
	{
		info = ft_strtrim(tokens[i], "\n");
		printf("[%s] %zu\n", info, ft_strlen(info));
		free(tokens[i]);
		free(info);
		i++;
	}
	printf("-----%d-----\n", i);
	free(tokens);
	printf("%p\n", data);
}

void	read_file(t_data *data, char *file)
{
	int		fd;
	char	*read_line;

	fd = rt_open(file, O_RDONLY, data);
	while (TRUE)
	{
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		if (ft_strlen(read_line) != 1 || read_line[0] != '\n')
			parse_line(data, read_line);
		free(read_line);
	}
	rt_close(fd, data);
}
