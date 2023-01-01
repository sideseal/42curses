/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:35:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 22:30:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_ratio(int s, int f, int cur)
{
	double	d;
	double	d1;

	d = f - s;
	d1 = cur - s;
	return (d1 / d);
}

static int	set_default_color(int z, t_map map)
{
	double	ratio;

	ratio = fabs(get_ratio(map.z_min, map.z_max, z));
	if (ratio < 0.3)
		return (0x0000FF00);
	else if (ratio < 0.45)
		return (0x0033FF33);
	else if (ratio < 0.6)
		return (0x0066FF66);
	else if (ratio < 0.75)
		return (0x0099FF99);
	else if (ratio < 0.9)
		return (0x00CCFFCC);
	else
		return (0x00FFFFFF);
}

static t_point	set_point(t_coord coord, t_fdf *fdf)
{
	t_point	new;

	new.x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2) * fdf->offset.zoom;
	new.y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2) * fdf->offset.zoom;
	new.z = coord.z * -1 * fdf->offset.z * fdf->offset.zoom;
	new.color = set_default_color(new.z, fdf->map);
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
