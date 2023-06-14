/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:45:45 by salee2            #+#    #+#             */
/*   Updated: 2023/06/02 17:45:48 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_point3	get_moved_point3(int keycode, t_point3 origin, \
const int *dir_to_key)
{
	int				dir;
	const double	dz[DIR_SIZE] = {0, 0, 0, 0, 1, -1};
	const double	dy[DIR_SIZE] = {0, 0, -1, 1, 0, 0};
	const double	dx[DIR_SIZE] = {-1, 1, 0, 0, 0, 0};

	dir = 0;
	while (dir < DIR_SIZE)
	{
		if (keycode == dir_to_key[dir])
			break ;
		++dir;
	}
	origin.z += dz[dir];
	origin.y += dy[dir];
	origin.x += dx[dir];
	return (origin);
}

void	move_camera(int keycode, t_vars *vars, const int *dir_to_move_key)
{
	t_point3	look_from;

	mlx_clear_window(vars->mlx, vars->win);
	look_from = get_moved_point3(keycode, vars->scene->camera.origin, \
	dir_to_move_key);
	vars->scene->camera = camera_(&vars->scene->canvas, look_from, \
	add(look_from, point3_(0, 0, -1)), 70);
	render(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

void	rotate_camera(int keycode, t_vars *vars, const int *dir_to_rotate_key)
{
	t_point3	look_at;

	mlx_clear_window(vars->mlx, vars->win);
	look_at = get_moved_point3(keycode, vars->scene->camera.origin, \
	dir_to_rotate_key);
	vars->scene->camera = camera_(&vars->scene->canvas, look_at, \
	point3_(0, 0, -1), 70);
	render(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}
