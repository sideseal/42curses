/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/20 02:09:53 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *str)
{
	perror(str);
	exit(1);
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
		fdf_lstadd_back(&(map->point), \
			fdf_lstnew(index_x, index_y, ft_atoi(vars_x[index_x])));
		free(vars_x[index_x]);
		index_x++;
	}
	free(vars_x);
}

// 파일 형식 검증 필요
void	read_and_set(t_fdf *fdf, char *path)
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

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		img_width = 720;
	int		img_height = 720;

	if (argc != 2)
		fdf_error("Usage: ./fdf [file]");
	fdf = init_fdf(fdf, img_width, img_height);
	read_and_set(fdf, argv[1]);
	// draw section
	my_mlx_pixel_put(fdf, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
	free_fdf(fdf);
	return (0);
}
