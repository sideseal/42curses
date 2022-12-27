/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:51:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/27 15:37:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*set_coord(t_map map, char *line, int index_y)
{
	char	**vars_x;
	int		index_x;
	t_coord	*coord;

	vars_x = ft_split(line, ' ');
	coord = malloc(sizeof(t_coord) * map.width);
	if (coord == NULL)
		fdf_error("Error: malloc ");
	index_x = 0;
	while (vars_x && vars_x[index_x])
	{
		coord[index_x] = init_coord(index_x - map.x_origin,\
				index_y - map.y_origin, ft_atoi(vars_x[index_x]));
		free(vars_x[index_x]);
		index_x++;
	}
	free(vars_x);
	return (coord);
}

static int	check_valid_file(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 5)
		fdf_error("Error: Not a valid file ");
	if (path[i - 1] == 'f' && path[i - 2] == 'd' \
	&& path[i - 3] == 'f' && path [i - 4] == '.')
		return (1);
	return (0);
}

static int	count_width(char *line)
{
	int	count;
	char	**vars_x;

	vars_x = ft_split(line, ' ');
	count = 0;
	while (vars_x && vars_x[count])
	{
		free(vars_x[count]);
		count++;
	}
	free(vars_x);
	return (count);
}

static void	read_map_info(t_fdf *fdf, char *path)
{
	int	fd;
	int	width;
	int	height;
	char	*read_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file open ");
	if (!check_valid_file(path))
		fdf_error("Error: Not a valid file ");
	read_line = get_next_line(fd);
	width = count_width(read_line);
	height = 1;
	while (1)
	{
		free(read_line);
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		height++;
	}
	if (close(fd) < 0)
		fdf_error("Error: file close ");
	fdf->map.width = width;
	fdf->map.height = height;
}

void	read_and_set(t_fdf *fdf, char *path)
{
	int		fd;
	int		index_y;
	char	*read_line;

	read_map_info(fdf, path);
	fdf->map.x_origin = fdf->map.width / 2;
	fdf->map.y_origin = fdf->map.height / 2;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file open ");
	fdf->coords = malloc(sizeof(t_coord *) * fdf->map.height);
	if (fdf->coords == NULL)
		fdf_error("Error: malloc ");
	index_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		fdf->coords[index_y] = set_coord(fdf->map, read_line, index_y);
		index_y++;
		free(read_line);
	}
	if (close(fd) < 0)
		fdf_error("Error: file close ");
}
