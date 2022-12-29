/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:31:18 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/29 22:09:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < SCREEN_WIDTH) && (0 <= y && y < SCREEN_HEIGHT))
	{
		dst = fdf->addr + ((y * fdf->line_len) + (x * fdf->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	plot_line(t_point s, t_point f, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	plot;

	dx = fdf_abs(f.x - s.x);
	dy = fdf_abs(f.y - s.y);
	if (dx >= dy)
	{
		plot = 2 * dy - dx;
		while (1)
		{
			my_mlx_pixel_put(fdf, s.x, s.y, 0x0000FF00);
			if (s.x == f.x)
				break ;
			if (plot < 0)
				plot += 2 * dy;
			else
			{
				if (s.y < f.y)
					s.y++;
				else
					s.y--;
				plot += 2 * (dy - dx);
			}
			if (s.x < f.x)
				s.x++;
			else
				s.x--;
		}
	}
	else
	{
		plot = 2 * dx - dy;
		while (1)
		{
			my_mlx_pixel_put(fdf, s.x, s.y, 0x0000FF00);
			if (s.y == f.y)
				break ;
			if (plot < 0)
				plot += 2 * dx;
			else
			{
				if (s.x < f.x)
					s.x++;
				else
					s.x--;
				plot += 2 * (dx - dy);
			}
			if (s.y < f.y)
				s.y++;
			else
				s.y--;
		}
	}
}

t_point	**convert_coords(t_fdf *fdf, int keycode)
{
	t_point	**points;
	t_point	*point;
	int		y;
	int		x;

	points = malloc(sizeof(t_point *) * fdf->map.height);
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		point = malloc(sizeof(t_point) * fdf->map.width);
		while (x < fdf->map.width)
		{
			point[x] = set_point(fdf->coords[y][x], fdf, keycode);
			x++;
		}
		points[y] = point;
		y++;
	}
	return (points);
}

void	set_draw(t_fdf *fdf)
{
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (fdf->img == NULL)
		fdf_error("Error: mlx ");
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_len, &fdf->endian);
	if (fdf->addr == NULL)
		fdf_error("Error: mlx ");
}

void	draw_frame(t_fdf *fdf, int keycode)
{
	t_point	**points;
	int		y;
	int		x;

	set_draw(fdf);
	points = convert_coords(fdf, keycode);
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				plot_line(points[y][x], points[y][x + 1], fdf);
			if (y < fdf->map.height - 1)
				plot_line(points[y][x], points[y + 1][x], fdf);
			x++;
		}
		free(points[y]);
		y++;
	}
	free(points);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
