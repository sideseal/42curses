/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:57 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:57 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_minirt_image(t_vars *vars)
{
	int		dy;
	int		dx;
	int		color;
	t_vec2	xy;
	t_scene	*scene;

	scene = vars->scene;
	dy = 0;
	while (dy <scene->canvas.height)
	{
		dx = 0;
		while (dx < scene->canvas.width)
		{
			xy.x = (double) dx / (scene->canvas.width - 1);
			xy.y = (double) dy / (scene->canvas.height - 1);
			scene->ray = primary_ray(&scene->camera, xy);
			color = ray_color(scene);
			my_mlx_pixel_put(&vars->img, dx, scene->canvas.height - 1 - dy, color);
			++dx;
		}
		++dy;
	}
	return ;
}

/*
void render(t_scene* scene)
{
	int			y;
	int			x;
	t_vec2		xy;
	t_color3	pixel_color;

	printf("P3\n%d %d\n255\n", scene->canvas.width,scene->canvas.height);
	y = scene->canvas.height - 1;
	while (y >= 0)
	{
		x = 0;
		while(x < scene->canvas.width)
		{
			xy.x = (double) x / (scene->canvas.width - 1);
			xy.y = (double) y / (scene->canvas.height - 1);
			scene->ray = primary_ray(&scene->camera, xy);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			++x;
		}
		--y;
	}
	return ;
}
*/
