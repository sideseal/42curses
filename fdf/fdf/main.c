/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/10 23:04:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_var *var)
{
	if (keycode == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

int	main(void)
{
	t_var	var;
	t_fdf	img;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1024, 1024, "Hello world!");
	img.img = mlx_new_image(var.mlx, 1024, 1024);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	for (int i = 0; i < 1024 - 1; i++)
	{
		for (int j = 0; j < 1024 - 1; j++)
		{
			double	r = (double)(1024 - j) / (1024 - 1);
			double	g = (double)(i) / (1024 - 1);
			double	b = 1;
			int	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
			my_mlx_pixel_put(&img, j, i, color);
		}
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, exit_hook, 0);
	mlx_loop(var.mlx);
	return (0);
}
