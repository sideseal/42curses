/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pracrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:54:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 22:54:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

int	write_color(t_color3 pixel_color, int t)
{
	return (t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_image		image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "pracRT");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	t_color3	pixel_color;
	t_sphere	*sp;


	sp = sphere(point3(0, 0, -5) , 2);
	for (int j = SCREEN_HEIGHT - 1; j >= 0; j--)
	{
		printf("rendering... %.2f%%", (float)(SCREEN_HEIGHT - j) / SCREEN_HEIGHT * 100);
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			pixel_color.x = (double)i / (SCREEN_WIDTH - 1);
			pixel_color.y = (double)j / (SCREEN_HEIGHT - 1);
			pixel_color.z = 0.25;
			my_mlx_pixel_put(&image, i, j, write_color(pixel_color, 1));
		}
		printf("\033[1A\n");
	}

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
