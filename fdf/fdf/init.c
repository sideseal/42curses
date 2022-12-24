/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:26:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/24 22:01:12 by gychoi           ###   ########.fr       */
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

t_coord	init_coord(int x, int y, int z)
{
	t_coord	new;

	new.x = (double)x;
	new.y = (double)y;
	new.z = (double)z;
	return (new);
}

t_fdf	*init_fdf(t_fdf *fdf)
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
	new->img = mlx_new_image(new->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (new->img == NULL)
		fdf_error("Error: mlx ");
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	new->map = init_map();
	new->coords = NULL;
	return (new);
}
