/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:29:46 by salee2            #+#    #+#             */
/*   Updated: 2023/05/31 17:29:48 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int	red_cross(void)
{
	exit(0);
}

void	exit_minirt(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

t_point3 	get_moved_camera(int keycode, t_point3 origin)
{
	int				dir;
	const double	dz[6] = {0, 0, 0, 0, 1, -1};
	const double	dy[6] = {0, 0, -1, 1, 0, 0};
	const double	dx[6] = {-1, 1, 0, 0, 0, 0};

	if (LEFT_ARROW <= keycode && keycode <= UP_ARROW)
		dir = keycode - LEFT_ARROW;
	else if (keycode == UP_NUM)
		dir = 5;
	else
		dir = 4;
	origin.z += dz[dir];
	origin.y += dy[dir];
	origin.x += dx[dir];
	return (origin);
}

void	move_camera(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	t_point3 look_from = get_moved_camera(keycode, vars->scene->camera.origin);
	vars->scene->camera = camera_(&vars->scene->canvas, look_from , add(look_from, point3_(0,0, -1)), 70);
	get_minirt_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

t_point3 	get_moved_at(int keycode, t_point3 origin)
{
	int				dir;
	const double	dz[6] = {0, 0, 0, 0, 1, -1};
	const double	dy[6] = {0, -1, 0, 1, 0, 0};
	const double	dx[6] = {-1, 0, 1, 0, 0, 0};

	if (A <= keycode && keycode <= D)
		dir = keycode - A;
	else if (keycode == W)
		dir = 3;
	else if (keycode == T)
		dir = 5;
	else
		dir = 4;
	origin.z += dz[dir];
	origin.y += dy[dir];
	origin.x += dx[dir];
	return (origin);
}

void	rotate_camera(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	t_point3 look_at = get_moved_at(keycode, vars->scene->camera.origin);
	vars->scene->camera = camera_(&vars->scene->canvas, look_at , point3_(0,0,-1), 70);
	get_minirt_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		exit_minirt(vars);
	else if ((LEFT_ARROW <= keycode && keycode <= UP_ARROW) || keycode == UP_NUM || keycode == DOWN_NUM)
		move_camera(keycode, vars);
	else if ((A <= keycode && keycode <= D) || keycode == W || keycode == T || keycode == V)
		rotate_camera(keycode, vars);
	return (0);
}
