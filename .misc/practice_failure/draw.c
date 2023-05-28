/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:15:42 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 19:50:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static double	_clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, t_color3 pixel)
{
	char	*dst;
	int		pixel_color;

	pixel.x = _clamp(pixel.x, 0, 0.999);
	pixel.y = _clamp(pixel.y, 0, 0.999);
	pixel.z = _clamp(pixel.z, 0, 0.999);
	pixel_color = (int)(255.999 * pixel.x) << 16 | \
				(int)(255.999 * pixel.y) << 8 | (int)(255.999 * pixel.z);
	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = pixel_color;
}
