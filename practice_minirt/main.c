/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:42:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 18:08:04 by gychoi           ###   ########.fr       */
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

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	canv = canvas(SCREEN_WIDTH, SCREEN_HEIGHT);
	cam = camera(canv, vec3(0, 0, 0));
	sp = sphere(point3(0, 0, -5), 2);
	for (int j = 0; j < SCREEN_HEIGHT; j++)
	{
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			u = (double)i / (canv.width - 1);
			v = 1 - (double)j / (canv.height - 1);
			ray = ray_primary(cam, u, v);
			pixel_color = ray_color(ray, sp);
			my_mlx_pixel_put(&image, i, j, write_color(0, pixel_color));
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
