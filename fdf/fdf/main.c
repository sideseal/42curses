/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/23 20:44:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
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

void	plot_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	plot;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (dx >= dy)
	{
		plot = 2 * dy - dx;
		while (x0 != x1)
		{
			my_mlx_pixel_put(fdf, x0, y0, 0x00FF0000);
			if (plot < 0)
				plot += 2 * dy;
			else
			{
				if (y0 < y1)
					y0++;
				else
					y0--;
				plot += 2 * (dy - dx);
			}
			if (x0 < x1)
				x0++;
			else
				x0--;
		}
	}
	else
	{
		plot = 2 * dx - dy;
		while (y0 != y1)
		{
			my_mlx_pixel_put(fdf, x0, y0, 0x00FF0000);
			if (plot < 0)
				plot += 2 * dx;
			else
			{
				if (x0 < x1)
					x0++;
				else
					x0--;
				plot += 2 * (dx - dy);
			}
			if (y0 < y1)
				y0++;
			else
				y0--;
		}
	}
}

void	rotate(t_fdf *fdf, int i, int j)
{
	t_point	curr = fdf->points[i][j];
	double	prev_x = curr.x;
	double	prev_y = curr.y;
	double	prev_z = curr.z;
	double	alpha = 0.5;
	double	beta = 0.5;
	double	gamma = 0.5;

	// rotate z
	fdf->points[i][j].x = (prev_x  - prev_y) * cos(3.14 / 6);
	fdf->points[i][j].y = (prev_x + prev_y) * sin(3.14 / 6) - prev_z;
}

void	set_margin(t_fdf *fdf)
{
	for (int i = 0; i < fdf->map.height; i++)
	{
		for (int j = 0; j < fdf->map.width; j++)
		{
			fdf->points[i][j].x *= 30;
			fdf->points[i][j].y *= 30;
			rotate(fdf, i, j);
		}
	}
}

void	draw_square(t_fdf *fdf)
{
	set_margin(fdf);
	for (int i = 0; i < fdf->map.height; i++)
	{
		for (int j = 0; j < fdf->map.width; j++)
		{
			if (j < fdf->map.width - 1)
				plot_line(fdf->points[i][j].x + 500, fdf->points[i][j].y + 500, fdf->points[i][j + 1].x + 500, fdf->points[i][j + 1].y + 500, fdf);
			if (i < fdf->map.height - 1)
				plot_line(fdf->points[i][j].x + 500, fdf->points[i][j].y + 500, fdf->points[i + 1][j].x + 500, fdf->points[i + 1][j].y + 500, fdf);
			t_point current = fdf->points[i][j];
//			if (current.z > 0)
//				for (int ii = -3; ii < 3; ii++)
//					for (int jj = -3; jj < 3; jj++)
//						my_mlx_pixel_put(fdf, current.x + 100 + ii, current.y + 100 + jj, 0x00FFFFFF);
		}
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		img_width = 720;
	int		img_height = 720;

	if (argc != 2)
		fdf_error("Usage: ./fdf [file] ");
	fdf = init_fdf(fdf);
	read_and_set(fdf, argv[1]);
	// draw section start
	draw_square(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
	// draw section end
	// free_fdf(fdf);
	return (0);
}
