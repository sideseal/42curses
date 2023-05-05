/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:42:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 22:16:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vars		vars;
	t_data		image;

	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_sphere	sp;
	t_object	*world;
	int			anti;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	canv = canvas(SCREEN_WIDTH, SCREEN_HEIGHT);
	cam = camera(canv, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990)));
	anti = 100;
	for (int j = 0; j < SCREEN_HEIGHT; j++)
	{
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			pixel_color = color3(0, 0, 0);
			for (int s = 0; s < anti; s++)
			{
				u = ((double)i + rand_num(anti)) / (canv.width - 1);
				v = 1 - ((double)j + rand_num(anti)) / (canv.height - 1);
				ray = ray_primary(cam, u, v);
				pixel_color = vadd_v(pixel_color, ray_color(ray, world));
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
