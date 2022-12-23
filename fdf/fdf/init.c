/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:26:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/23 16:31:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	init_map(void)
{
	t_map	new;

	new.width = 0;
	new.height = 0;
	return (new);
}

t_point	init_point(int x, int y, int z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_fdf	*init_fdf(t_fdf *fdf)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
		fdf_error("Error: malloc ");
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	new->img = mlx_new_image(new->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	new->map = init_map();
	new->points = NULL;
	return (new);
}
