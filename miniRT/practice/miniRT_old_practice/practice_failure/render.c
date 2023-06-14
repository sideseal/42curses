/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:16:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 22:59:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

// something_wrond

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->camera = camera(point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990), color3(1, 1, 1)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmults(color3(1, 1, 1), ka);
	return (scene);
}

void	render(t_mlx mlx, t_img img)
{
	t_scene		*scene;
	int			i;
	int			j;
	double		u;
	double		v;

	scene = scene_init();
	j = IMAGE_HEIGHT - 1;
	while (j >= 0)
	{
		printf("rendering... %.2f%%", \
				(float)(IMAGE_HEIGHT - j) / IMAGE_HEIGHT * 100);
		i = 0;
		while (i < IMAGE_WIDTH)
		{
			u = (double)i / (IMAGE_WIDTH - 1);
			v =  1 - (double)j / (IMAGE_HEIGHT - 1);
			scene->ray = ray_primary(scene->camera, u, v);
			my_mlx_pixel_put(&img, i, j, ray_color(scene->ray, scene->world));
			i++;
		}
		j--;
		printf("\033[1A\n");
	}
	printf("\n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
}
