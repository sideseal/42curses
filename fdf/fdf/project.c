/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:55 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/27 23:17:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, double theta)
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

void	rotate_y(t_point *point, double theta)
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

void	rotate_z(t_point *point, double theta)
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
static void	isometric(t_point *p)
{
//	rotate_y(p, 3.14/6);
//	rotate_x(p, 3.14/6);
	//rotate_x(p, 3.14 / 45);
	rotate_x(p, -0.7071);
	//rotate_y(p, 3.14 / (180 / 35));
	rotate_y(p, 0.5774);
	rotate_z(p, 0.5236);
}

void	init_projection(t_coord coord, t_point *p, t_fdf *fdf)
{
	fdf->angle.alpha = -0.7071;
	fdf->angle.beta = 0.5774;
	fdf->angle.gamma = 0.5236;
	fdf->offset.x = 0;
	fdf->offset.y = 0;
	fdf->offset.z = 0;
	fdf->offset.zoom = 1;
	p->x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2);
	p->y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2);
	p->z = coord.z * -1;
}

// 벡터로 변환할 것.
//static void	iisometric(t_point *p)
//{
//	double	prev_x;
//	double	prev_y;
//
//	prev_x = p->x;
//	prev_y = p->y;
//	p->x = (prev_x - prev_y) * cos(0.5236);
//	p->y = (prev_x + prev_y) * sin(0.5236) - p->z;
//}
static void	rotate(t_point *p, t_angle *angle)
{
	rotate_x(p, angle->alpha);
	rotate_y(p, angle->beta);
	rotate_z(p, angle->gamma);
}

// 좌표계 변환을 위해 z축에 -1을 곱하는가? -> 왼손에서 오른손으로!
t_point	set_point(t_coord coord, t_fdf *fdf, int keycode)
{
	t_point	new;

	new.x = coord.x * (SCREEN_WIDTH / fdf->map.width / 2) * fdf->offset.zoom;
	new.y = coord.y * (SCREEN_HEIGHT / fdf->map.height / 2) * fdf->offset.zoom;
	new.z = coord.z * -1 * fdf->offset.z;
	new.color = 0x0;
	if (keycode == KEY_ISO)
	{
		init_projection(coord, &new, fdf);
		isometric(&new);
	}
	else
		rotate(&new, &fdf->angle);
	new.x += SCREEN_WIDTH / 2 + fdf->offset.x;
	new.y += SCREEN_HEIGHT / 2 + fdf->offset.y;
	return (new);
}
