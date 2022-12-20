/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/21 01:55:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	plot_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	for (;;) {
		my_mlx_pixel_put(fdf, x0, y0, 0x00FF0000);
		if (x0 == x1 && y0 == y1) break ;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

int	mouse_move(t_fdf *fdf)
{
	int	x = 0;
	int	y = 0;

	mlx_mouse_get_pos(fdf->win, &x, &y);
	//plot_line(360, 360, x, y, fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		img_width = 720;
	int		img_height = 720;

	if (argc != 2)
		fdf_error("Usage: ./fdf [file] ");
	fdf = init_fdf(fdf, img_width, img_height);
	read_and_set(fdf, argv[1]);
	// draw section start
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop_hook(fdf->mlx, mouse_move, fdf);
	mlx_loop(fdf->mlx);
	// draw section end
	free_fdf(fdf);
	return (0);
}
