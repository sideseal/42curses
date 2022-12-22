/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:26:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/22 23:16:19 by gychoi           ###   ########.fr       */
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

// img_width, height 나중에 변경해야 한다.
t_fdf	*init_fdf(t_fdf *fdf, int win_width, int win_height)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (!new)
		fdf_error("Error: malloc");
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, win_width, win_height, "fdf");
	new->img = mlx_new_image(new->mlx, win_width, win_height);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	new->map = init_map();
	return (new);
}
