/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:26:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/31 23:32:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	init_map(void)
{
	t_map	new;

	new.width = 0;
	new.height = 0;
	new.x_origin = 0;
	new.y_origin = 0;
	return (new);
}

t_coord	init_coord(int x, int y, int z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

static t_angle	init_angle(void)
{
	t_angle	new;

	new.alpha = M_PI / 4 * -1;
	new.beta = asin(tan(M_PI / 6));
	new.gamma = 0;
	return (new);
}

static t_offset	init_offset(void)
{
	t_offset	new;

	new.x = 0;
	new.y = 0;
	new.z = 1.0;
	new.zoom = 1.0;
	return (new);
}

t_fdf	*init_fdf(void)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
		fdf_error("Error: malloc ");
	new->mlx = mlx_init();
	if (new->mlx == NULL)
		fdf_error("Error: mlx ");
	new->win = mlx_new_window(new->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (new->win == NULL)
		fdf_error("Error: mlx ");
	new->img = NULL;
	new->addr = NULL;
	new->map = init_map();
	new->coords = NULL;
	new->angle = init_angle();
	new->offset = init_offset();
	return (new);
}
