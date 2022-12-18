/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/19 03:02:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *str)
{
	perror(str);
	exit(1);
}

t_point	*fdf_lstnew(int x, int y, int z)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		fdf_error("Error: malloc");
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

t_point	*fdf_lstlast(t_point *point)
{
	if (!point)
		return (NULL);
	while (point->next != NULL)
		point = point->next;
	return (point);
}

void	fdf_lstadd_back(t_point **point, t_point *new)
{
	t_point	*curr;

	if (!point || !new)
		return ;
	if (!*point)
	{
		*point = new;
		return ;
	}
	curr = fdf_lstlast(*point);
	curr->next = new;
}

void	set_point(t_map *map, char *line, int index_y)
{
	char	**vars_x;
	int	index_x;

	vars_x = ft_split(line, ' ');
	index_x = 0;
	while (vars_x[index_x])
	{
		if (*vars_x[index_x] == '\n')
			break ;
		fdf_lstadd_back(&(map->point), fdf_lstnew(index_x, index_y, ft_atoi(vars_x[index_x])));
		free(vars_x[index_x]);
		index_x++;
	}
	free(vars_x);
}

void	read_file(t_fdf *fdf, char *path)
{
	int		fd;
	int		index_y;
	char	*read_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file");
	index_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		set_point(fdf->map, read_line, index_y);
		free(read_line);
		index_y++;
		// fdf->map->width를 세기 위한 모듈 필요.
		fdf->map->height++;
	}
}

t_map	*init_map(void)
{
	t_map	*new;

	new = malloc(sizeof(t_map *));
	if (!new)
		fdf_error("Error: malloc");
	new->width = 0;
	new->height = 0;
	new->point = NULL;
	return (new);
}

t_fdf	*init_fdf(t_fdf *fdf, int img_width, int img_height)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf *));
	if (!new)
		fdf_error("Error: malloc");
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, img_width, img_height, "fdf");
	new->img = mlx_new_image(new->mlx, img_width, img_height);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	new->map = init_map();
	return (new);
}

void	iter(t_fdf *fdf)
{
	t_point	*curr;

	curr = fdf->map->point;
	while (curr)
	{
		printf("%d, %d, %d\n", curr->x, curr->y, curr->z);
		curr = curr->next;
	}
	printf("map: %d, %d\n", fdf->map->width, fdf->map->height);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		img_width = 720;
	int		img_height = 720;

	if (argc != 2)
		fdf_error("Usage: ./fdf [file]");
	fdf = init_fdf(fdf, img_width, img_height);
	read_file(fdf, argv[1]);
	iter(fdf);
	return (0);
}
