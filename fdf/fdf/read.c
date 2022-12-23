/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:51:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/23 18:07:22 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*set_point(t_map map, char *line, int index_y)
{
	char	**vars_x;
	int		index_x;
	t_point	*point;

	vars_x = ft_split(line, ' ');
	point = malloc(sizeof(t_point) * map.width);
	if (point == NULL)
		fdf_error("Error: malloc ");
	index_x = 0;
	while (vars_x && vars_x[index_x])
	{
		point[index_x] = init_point(index_x, index_y, ft_atoi(vars_x[index_x]));
		free(vars_x[index_x]);
		index_x++;
	}
	free(vars_x);
	return (point);
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
	while (vars_x[count])
	{
		if (*vars_x[count] == '\n')
			break ;
		count++;
		free(vars_x[count]);
	}
	free(vars_x);
	return (count);
}

static void	read_map(t_fdf *fdf, char *path)
{
	int	fd;
	int	width;
	int	height;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file open ");
	if (!check_valid_file(path))
		fdf_error("Error: Not a valid file ");
	width = count_width(get_next_line(fd));
	height = 1;
	while (get_next_line(fd))
		height++;
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

	read_map(fdf, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file open ");
	fdf->points = malloc(sizeof(t_point *) * fdf->map.height);
	if (fdf->points == NULL)
		fdf_error("Error: malloc ");
	index_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		fdf->points[index_y] = set_point(fdf->map, read_line, index_y);
		index_y++;
		free(read_line);
	}
	if (close(fd) < 0)
		fdf_error("Error: file close ");
}
