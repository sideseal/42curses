/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:25:39 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 21:13:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(void)
{
	t_data	*data;
	int		width;
	int		height;

	data = rt_malloc(sizeof(t_data), NULL);
	data->scene.canvas = set_canvas(HEIGHT);
	data->scene.lights = NULL;
	data->scene.objects = NULL;
	width = data->scene.canvas.width;
	height = data->scene.canvas.height;
	data->mlx = NULL;
	data->win = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->mlx = rt_mlx_init(data);
	data->win = rt_mlx_new_window(data, width, height, "miniRT");
	data->img.img = rt_mlx_new_image(data, width, height);
	data->img.addr = rt_mlx_get_data_addr(data);
	return (data);
}

t_light	*init_light(t_data *data)
{
	t_light		*light;
	t_point3	origin;
	t_color3	color;
	double		bright_ratio;

	origin = point3_(0, 0, 0);
	color = color3_(255, 255, 255);
	bright_ratio = 1.0;
	light = light_(origin, color, bright_ratio, data);
	return (light);
}
