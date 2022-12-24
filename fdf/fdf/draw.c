/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:31:18 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/25 00:00:33 by gychoi           ###   ########.fr       */
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

static void	plot_line(t_point s, t_point f, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	plot;

	dx = fabs(f.x - s.x);
	dy = fabs(f.y - s.y);
	if (dx >= dy)
	{
		plot = 2 * dy - dx;
		while ((int)s.x != (int)f.x)
		{
			my_mlx_pixel_put(fdf, s.x, s.y, 0x0000FF00);
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
		while ((int)s.y != (int)f.y)
		{
			my_mlx_pixel_put(fdf, s.x, s.y, 0x0000FF00);
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

void	draw_frame(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				plot_line(set_point(fdf->coords[y][x], fdf->map), \
					set_point(fdf->coords[y][x + 1], fdf->map), fdf);
			if (y < fdf->map.height - 1)
				plot_line(set_point(fdf->coords[y][x], fdf->map), \
					 set_point(fdf->coords[y + 1][x], fdf->map), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
