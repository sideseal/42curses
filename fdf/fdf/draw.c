/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:31:18 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/27 22:03:32 by gychoi           ###   ########.fr       */
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

//void	plot_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
//{
//	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
//	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
//	int err = dx + dy, e2;
//
//	for (;;) {
//		my_mlx_pixel_put(fdf, x0, y0, 0x00FF0000);
//		if (x0 == x1 && y0 == y1) break ;
//		e2 = 2 * err;
//		if (e2 >= dy) { err += dy; x0 += sx; }
//		if (e2 <= dx) { err += dx; y0 += sy; }
//	}
//}

static void	plot_line(t_pixel s, t_pixel f, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	plot;

	dx = abs(f.x - s.x);
	dy = abs(f.y - s.y);
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

t_pixel	pixelize(t_point point)
{
	t_pixel	new;

	new.x = (int)point.x;
	new.y = (int)point.y;
	new.z = (int)point.z;
	new.color = point.color;
	return (new);
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
				plot_line(pixelize(points[y][x]), pixelize(points[y][x + 1]), fdf);
			if (y < fdf->map.height - 1)
				plot_line(pixelize(points[y][x]), pixelize(points[y + 1][x]), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
