/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 20:52:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_data *data)
{
	t_scene	scene;
	int		i;
	int		j;

	scene = data->scene;
	j = scene.canvas.height - 1;
	while (j >= 0)
	{
		printf("rendering... %.2f%%", \
			(float)(scene.canvas.height - j) / scene.canvas.height * 100);
		i = 0;
		while (i < scene.canvas.width)
		{
			rt_mlx_pixel_put(&data->img, i, j, color3_(0.5, 0.3, 0.4));
			i++;
		}
		j--;
		printf("\033[1A\n");
	}
	printf("\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
