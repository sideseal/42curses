/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pracrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:54:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 21:58:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "object.h"
#include "structure.h"
#include "ray.h"
#include "light.h"
#include "list.h"

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

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

int	write_color(t_color3 *pixel_color, double t)
{
	return ((int)t << 24 | (int)(255 * pixel_color->x) << 16 | (int)(255 * pixel_color->y) << 8 | (int)(255 * pixel_color->z));
}

int	trgb(t_color3 *color, double t)
{
	color->x = clamp(color->x, 0, 0.999);
	color->y = clamp(color->y, 0, 0.999);
	color->z = clamp(color->z, 0, 0.999);
	return (write_color(color, t));
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
	t_color3	pixel;
	t_ray		pixel_ray;
	t_vec3		raydir;
	t_vec3		eyepos;
	t_light		lt;

	lt = light(point3(0.0f, 1.0f, -1.0f));

	t_obj_list	*list;

	t_sphere	*sp1;
	sp1 = sphere(point3(0.5f, 0.0f, 0.5f) , 0.4f, color3(0.5f, 0.5f, 0.5f));
	sp1->obj.amb = color3(0.2f, 0.2f, 0.2f);
	sp1->obj.dif = color3(1.0f, 0.2f, 0.2f);
	sp1->obj.spec = color3(0.5f, 0.5f, 0.5f);
	sp1->obj.alpha = 10.0f;

	t_sphere	*sp2;
	sp2 = sphere(point3(0.0f, 0.0f, 1.0f) , 0.4f, color3(0.5f, 0.5f, 0.5f));
	sp2->obj.amb = color3(0.2f, 0.2f, 0.2f);
	sp2->obj.dif = color3(0.2f, 1.0f, 0.2f);
	sp2->obj.spec = color3(0.5f, 0.5f, 0.5f);
	sp2->obj.alpha = 10.0f;

	t_sphere	*sp3;
	sp3 = sphere(point3(-0.5f, 0.0f, 1.5f) , 0.4f, color3(0.5f, 0.5f, 0.5f));
	sp3->obj.amb = color3(0.2f, 0.2f, 0.2f);
	sp3->obj.dif = color3(0.2f, 0.2f, 1.0f);
	sp3->obj.spec = color3(0.5f, 0.5f, 0.5f);
	sp3->obj.alpha = 10.0f;

	list = obj_list(SP, sp3);
	oadd(&list, obj_list(SP, sp2));
	oadd(&list, obj_list(SP, sp1));

	eyepos = point3(0.0f, 0.0f, -1.5f);
	for (int j = SCREEN_HEIGHT - 1; j >= 0; j--)
	{
		printf("rendering... %.2f%%", (float)(SCREEN_HEIGHT - j) / SCREEN_HEIGHT * 100);
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			world_pixel = transform_screen_to_world(i, j);
			//raydir = vec3(0, 0, 1);
			pixel_ray = ray(world_pixel, vunit(vsub(world_pixel, eyepos)));
			pixel = trace_ray(pixel_ray, list, lt);
			my_mlx_pixel_put(&image, i, j, trgb(&pixel, 1.0));
		}
		printf("\033[1A\n");
	}

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
