/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pracrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:54:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/13 23:06:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "object.h"
#include "structure.h"
#include "ray.h"
#include "light.h"

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

int	write_color(t_color3 pixel_color, float t)
{
	return ((int)t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

t_color3	transform_screen_to_world(int x, int y)
{
	double	xscale;
	double	yscale;
	double	aspect;

	xscale = 2.0f / (SCREEN_WIDTH - 1);
	yscale = 2.0f / (SCREEN_HEIGHT - 1);
	aspect = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	return (color3((x * xscale - 1.0f) * aspect, -y * yscale + 1.0f, 0.0f));
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_image		image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "pracRT");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	t_color3	world_pixel;
	t_sphere	*sp;
	t_ray		pixel_ray;
	t_vec3		raydir;
	t_light		lt;

	sp = sphere(point3(0.0f, 0.0f, 0.5f) , 0.5f, color3(1, 1, 1));
	sp->amb = vec3(0.0f, 0.0f, 0.0f);
	sp->diff = vec3(0.0f, 0.0f, 1.0f);
	sp->spec = vec3(1.0f, 1.0f, 1.0f);
	sp->alpha = 9.0f;
	sp->ks = 0.8f;

	lt = light(vec3(0.0f, 0.0f, -1.0f));

	for (int j = SCREEN_HEIGHT - 1; j >= 0; j--)
	{
		printf("rendering... %.2f%%", (float)(SCREEN_HEIGHT - j) / SCREEN_HEIGHT * 100);
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			world_pixel = transform_screen_to_world(i, j);
			raydir = vec3(0, 0, 1);
			pixel_ray = ray(world_pixel, raydir);
			my_mlx_pixel_put(&image, i, j, write_color(trace_ray(pixel_ray, sp, lt), 1.0));
		}
		printf("\033[1A\n");
	}

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
