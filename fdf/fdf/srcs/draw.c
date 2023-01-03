/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:31:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/03 16:38:56 by gychoi           ###   ########.fr       */
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

static void	plot_dx_big(t_point s, t_point f, t_fdf *fdf, t_delta delta)
{
	int	plot;

	plot = 2 * delta.dy - delta.dx;
	while (1)
	{
		my_mlx_pixel_put(fdf, s.x, s.y, s.color);
		if (s.x == f.x)
			break ;
		if (plot < 0)
			plot += 2 * delta.dy;
		else
		{
			if (s.y < f.y)
				s.y++;
			else
				s.y--;
			plot += 2 * (delta.dy - delta.dx);
		}
		if (s.x < f.x)
			s.x++;
		else
			s.x--;
	}
}

static void	plot_dy_big(t_point s, t_point f, t_fdf *fdf, t_delta delta)
{
	int	plot;

	plot = 2 * delta.dx - delta.dy;
	while (1)
	{
		my_mlx_pixel_put(fdf, s.x, s.y, s.color);
		if (s.y == f.y)
			break ;
		if (plot < 0)
			plot += 2 * delta.dx;
		else
		{
			if (s.x < f.x)
				s.x++;
			else
				s.x--;
			plot += 2 * (delta.dx - delta.dy);
		}
		if (s.y < f.y)
			s.y++;
		else
			s.y--;
	}
}

static void	plot_line(t_point s, t_point f, t_fdf *fdf)
{
	t_delta	delta;

	delta.dx = fdf_abs(f.x - s.x);
	delta.dy = fdf_abs(f.y - s.y);
	if (delta.dx >= delta.dy)
		plot_dx_big(s, f, fdf, delta);
	else
		plot_dy_big(s, f, fdf, delta);
}

void	draw_frame(t_fdf *fdf)
{
	t_point	**points;
	int		y;
	int		x;

	init_draw(fdf);
	points = set_points(fdf);
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
