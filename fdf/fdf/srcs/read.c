/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:51:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/31 23:37:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*get_coord(t_map map, char *line, int index_y)
{
	char	**vars_x;
	int		index_x;
	t_coord	*coord;

	vars_x = ft_split(line, ' ');
	coord = fdf_malloc(sizeof(t_coord) * map.width);
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

static void	check_valid_file(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 5)
		fdf_error("Error: Not a valid file ");
	if (path[i - 1] != 'f' || path[i - 2] != 'd' \
	|| path[i - 3] != 'f' || path [i - 4] != '.')
		fdf_error("Error: Not a valid file ");
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

	check_valid_file(path);
	fd = fdf_open(path, O_RDONLY);
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
	fdf->map.width = width;
	fdf->map.height = height;
	fdf_close(fd);
}

void	read_and_set(t_fdf *fdf, char *path)
{
	int		fd;
	int		index_y;
	char	*read_line;

	read_map_info(fdf, path);
	fdf->map.x_origin = fdf->map.width / 2;
	fdf->map.y_origin = fdf->map.height / 2;
	fd = fdf_open(path, O_RDONLY);
	fdf->coords = fdf_malloc(sizeof(t_coord *) * fdf->map.height);
	index_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		fdf->coords[index_y] = get_coord(fdf->map, read_line, index_y);
		index_y++;
		free(read_line);
	}
	fdf_close(fd);
}
