/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:23:30 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 22:37:51 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	trgb_anti(t_color3 *color, int anti, int t)
{
	double	scale;

	if (anti == 0)
		anti = 1;
	scale = 1 / (double)anti;
	color->x = clamp((color->x * scale), 0, 0.999);
	color->y = clamp((color->y * scale), 0, 0.999);
	color->z = clamp((color->z * scale), 0, 0.999);
	return (write_color(t, *color));
}

// t : transparency
int	write_color(int t, t_color3 pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}
