/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:26:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/21 00:53:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		fdf_error("Error: malloc");
	new->width = 0;
	new->height = 0;
	new->point = NULL;
	return (new);
}

t_fdf	*init_fdf(t_fdf *fdf, int img_width, int img_height)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (!new)
		fdf_error("Error: malloc");
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, img_width, img_height, "fdf");
	new->img = mlx_new_image(new->mlx, img_width, img_height);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	new->map = init_map();
	return (new);
}
