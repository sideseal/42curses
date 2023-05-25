/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:16:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 20:22:47 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "draw.h"
#include "init.h"
#include "libvec.h"
#include "mlx.h"
#include "object.h"
#include "pracrt.h"
#include "ray.h"
#include "render.h"
#include <stdio.h>

void	render(t_mlx mlx, t_img img)
{
	t_camera	cam;
	t_ray		ray;
	t_sphere	sp;
	int			i;
	int			j;

	cam = camera(point3(0, 0, 0));
	sp = sphere(point3(0, 0, -5), 2.0);
	j = IMAGE_HEIGHT - 1;
	while (j >= 0)
	{
		printf("rendering... %.2f%%", \
				(float)(IMAGE_HEIGHT - j) / IMAGE_HEIGHT * 100);
		i = 0;
		while (i < IMAGE_WIDTH)
		{
			ray = ray_primary(cam, (double)i / (IMAGE_WIDTH - 1), 1 - (double)j / (IMAGE_HEIGHT - 1));
			my_mlx_pixel_put(&img, i, j, ray_color(ray, sp));
			i++;
		}
		j--;
		printf("\033[1A\n");
	}
	printf("\n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
}
