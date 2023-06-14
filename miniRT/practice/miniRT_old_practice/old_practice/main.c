/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:42:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 22:58:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(SCREEN_WIDTH, SCREEN_HEIGHT);
	scene->camera = camera(scene->canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmul_d(color3(1, 1, 1), ka);
	return (scene);
}

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vars		vars;
	t_data		image;

	double		u;
	double		v;
	t_color3	pixel_color;
	t_scene		*scene;
	int			anti;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	scene = scene_init();
	anti = 10;
	for (int j = 0; j < scene->canvas.height; j++)
	{
		for (int i = 0; i < scene->canvas.width; i++)
		{
			pixel_color = color3(0, 0, 0);
			for (int s = 0; s < anti; s++)
			{
				u = ((double)i + rand_num(anti)) / (scene->canvas.width - 1);
				v = 1 - ((double)j + rand_num(anti)) / (scene->canvas.height - 1);
				scene->ray = ray_primary(scene->camera, u, v);
				pixel_color = vadd_v(pixel_color, ray_color(scene));
			}
			my_mlx_pixel_put(&image, i, j, trgb_anti(&pixel_color, anti, 0));
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
