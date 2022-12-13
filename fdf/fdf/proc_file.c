/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:09:43 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/13 20:51:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	get_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	return (width);
}

char	**read_from_file(t_ctx *ctx, char *path)
{
	int		fd;
	char	*line;
	char	*read_line;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error();
	line = malloc(sizeof(char));
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		line = ft_strjoin(line, read_line);
		free(read_line);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
