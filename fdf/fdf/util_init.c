/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:16:27 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/13 21:00:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(t_ctx *ctx, int img_width, int img_height)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf *));
	if (!new)
		fdf_error();
	new->bpp = 0;
	new->line_len = 0;
	new->endian = 0;
	new->img = mlx_new_image(ctx->mlx, img_width, img_height);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->line_len, &new->endian);
	return (new);
}

t_ctx	*init_ctx(char *path, int img_width, int img_height)
{
	t_ctx	*new;

	new = malloc(sizeof(t_ctx *));
	if (!new)
		fdf_error();
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, img_width, img_height, "fdf");
	new->map = read_from_file(new, path);
	new->width = get_width(new->map[0]);
	new->height = get_height(new->map);
	return (new);
}
