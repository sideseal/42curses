/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:51:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/21 00:51:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_point(t_map *map, char *line, int index_y)
{
	char	**vars_x;
	int	index_x;

	vars_x = ft_split(line, ' ');
	index_x = 0;
	while (vars_x[index_x])
	{
		if (*vars_x[index_x] == '\n')
			break ;
		fdf_lstadd_back(&(map->point), \
			fdf_lstnew(index_x, index_y, ft_atoi(vars_x[index_x])));
		free(vars_x[index_x]);
		index_x++;
	}
	free(vars_x);
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
		free(vars_x[count]);
		count++;
	}
	free(vars_x);
	return (count);
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

void	read_and_set(t_fdf *fdf, char *path)
{
	int		fd;
	int		index_y;
	char	*read_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file descriptor ");
	if (!check_valid_file(path))
		fdf_error("Error: Not a valid file ");
	index_y = 0;
	read_line = get_next_line(fd);
	fdf->map->width = count_width(read_line);
	while (read_line > 0)
	{
		set_point(fdf->map, read_line, index_y);
		free(read_line);
		index_y++;
		fdf->map->height++;
		read_line = get_next_line(fd);
	}
}
