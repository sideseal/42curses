/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:35:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/31 23:41:46 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	set_point(t_coord coord, t_fdf *fdf, int keycode)
{
	t_point	new;

	new.x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2) * fdf->offset.zoom;
	new.y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2) * fdf->offset.zoom;
	new.z = coord.z * -1 * fdf->offset.z * fdf->offset.zoom;
	if (keycode == KEY_ISO)
		isometric(coord, &new, fdf);
	else
	{
		rotate_x(&new, fdf->angle.alpha);
		rotate_y(&new, fdf->angle.beta);
		rotate_z(&new, fdf->angle.gamma);
	}
	new.x += SCREEN_WIDTH / 2 + fdf->offset.x;
	new.y += SCREEN_HEIGHT / 2 + fdf->offset.y;
	new.x = (int)new.x;
	new.y = (int)new.y;
	new.z = (int)new.z;
	new.color = 0x0000FF00;
	return (new);
}

t_point	**set_points(t_fdf *fdf, int keycode)
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
			point[x] = set_point(fdf->coords[y][x], fdf, keycode);
			x++;
		}
		points[y] = point;
		y++;
	}
	return (points);
}
