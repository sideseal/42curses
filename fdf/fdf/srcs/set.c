/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:35:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/04 00:27:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_default_color(int z, t_map map)
{
	double	ratio;

	ratio = get_ratio(map.z_min * 2, map.z_max * 2, z * -1);
	if (ratio < 0.2)
		return (0x0000FF00);
	else if (ratio < 0.5)
		return (0x0088FF00);
	else if (ratio < 0.8)
		return (0x00FFFF00);
	else
		return (0x00FFFFFF);
}

static double	get_z_margin(t_fdf *fdf)
{
	double	adj_x;
	double	adj_y;
	double	x_margin;
	double	y_margin;

	adj_x = 10;
	x_margin = fdf->map.x_margin;
	while (x_margin < fdf->map.width)
	{
		x_margin *= 10;
		adj_x *= 0.1;
	}
	adj_y = 10;
	y_margin = fdf->map.y_margin;
	while (y_margin < fdf->map.height)
	{
		y_margin *= 10;
		adj_y *= 0.1;
	}
	return ((adj_x + adj_y) / 2);
}

void	set_coord_margin(t_fdf *fdf)
{
	fdf->map.x_margin = (double)SCREEN_WIDTH / fdf->map.width / 2;
	if (fdf->map.x_margin < 1)
	{
		while (fdf->map.x_margin < 1)
			fdf->map.x_margin += 0.1;
	}
	fdf->map.y_margin = (double)SCREEN_HEIGHT / fdf->map.height / 2;
	if (fdf->map.y_margin < 1)
	{
		while (fdf->map.y_margin < 1)
			fdf->map.y_margin += 0.1;
	}
	fdf->map.z_margin = get_z_margin(fdf);
	fdf->map.z_max *= fdf->map.z_margin;
	fdf->map.z_min *= fdf->map.z_margin;
}

static t_point	set_point(t_coord coord, t_fdf *fdf)
{
	t_point	new;
	double	bending;

	new.x = coord.x * fdf->map.x_margin;
	new.y = coord.y * fdf->map.y_margin;
	new.z = coord.z * -1 * fdf->offset.z * fdf->map.z_margin;
	bending = (new.x * new.x * fdf->offset.bend) \
		+ (new.y * new.y * fdf->offset.bend);
	new.z += bending;
	new.color = set_default_color(new.z, fdf->map);
	new.x *= fdf->offset.zoom;
	new.y *= fdf->offset.zoom;
	new.z *= fdf->offset.zoom;
	rotate_x(&new, fdf->angle.alpha);
	rotate_y(&new, fdf->angle.beta);
	rotate_z(&new, fdf->angle.gamma);
	new.x += SCREEN_WIDTH / 2 + fdf->offset.x;
	new.y += SCREEN_HEIGHT / 2 + fdf->offset.y;
	new.x = (int)new.x;
	new.y = (int)new.y;
	new.z = (int)new.z;
	return (new);
}

t_point	**set_points(t_fdf *fdf)
{
	t_point	**points;
	t_point	*point;
	int		y;
	int		x;

	points = fdf_malloc(sizeof(t_point *) * fdf->map.height);
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		point = fdf_malloc(sizeof(t_point) * fdf->map.width);
		while (x < fdf->map.width)
		{
			point[x] = set_point(fdf->coords[y][x], fdf);
			x++;
		}
		points[y] = point;
		y++;
	}
	return (points);
}
