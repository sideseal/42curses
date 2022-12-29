/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:55 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/29 22:50:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = point->x;
	new_y = (point->y * cos(theta)) + (point->z * sin(theta) * -1);
	new_z = (point->y * sin(theta)) + (point->z * cos(theta));
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}

static void	rotate_y(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = (point->x * cos(theta)) + (point->z * sin(theta));
	new_y = point->y;
	new_z = (point->x * sin(theta) * -1) + (point->z * cos(theta));
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}

static void	rotate_z(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = (point->x * cos(theta)) + (point->y * sin(theta) * -1);
	new_y = (point->x * sin(theta)) + (point->y * cos(theta));
	new_z = point->z;
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}

// https://gaussian37.github.io/math-la-rotation_matrix/
// y축으로 45도 돌리고, y축으로 30도 돌리면, 120도, 30도 차이가 난다. 여기서 z축으로 돌리는 이유는, 우리가 원하는 관점을 갖기 위해...
// https://ko.wikipedia.org/wiki/등축_투영법
//rotate_x(p, 3.14 / 45);
//rotate_y(p, 3.14 / (180 / 35));
//fdf->angle.alpha = -0.6981;
//fdf->angle.beta = 0.5774;
//fdf->angle.gamma = 0.5236;
static void	init_isometric(t_coord coord, t_point *p, t_fdf *fdf)
{
	fdf->angle.alpha = M_PI / 4 * -1;
	fdf->angle.beta = asin(tan(M_PI / 6));
	fdf->angle.gamma = 0;
	fdf->offset.x = 0;
	fdf->offset.y = 0;
	fdf->offset.z = 1.0;
	fdf->offset.zoom = 1.0;
	p->x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2);
	p->y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2);
	p->z = coord.z * -1;
	rotate_x(p, fdf->angle.alpha);
	rotate_y(p, fdf->angle.beta);
	rotate_z(p, fdf->angle.gamma);
}

// 좌표계 변환을 위해 z축에 -1을 곱하는가? -> 왼손에서 오른손으로!
t_point	set_point(t_coord coord, t_fdf *fdf, int keycode)
{
	t_point	new;

	new.x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2) * fdf->offset.zoom;
	new.y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2) * fdf->offset.zoom;
	new.z = coord.z * -1 * fdf->offset.z * fdf->offset.zoom;
	if (keycode == KEY_ISO)
		init_isometric(coord, &new, fdf);
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
	new.color = 0x0;
	return (new);
}
