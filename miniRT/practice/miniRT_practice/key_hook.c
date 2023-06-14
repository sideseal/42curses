/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:45:02 by salee2            #+#    #+#             */
/*   Updated: 2023/06/02 17:45:04 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	exit_minirt(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_scene(vars->scene);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int			i;
	const int	dir_to_move_key[DIR_SIZE] = {LEFT_ARROW, RIGHT_ARROW, \
	DOWN_ARROW, UP_ARROW, DOWN_NUM, UP_NUM};
	const int	dir_to_rotate_key[DIR_SIZE] = {A, D, S, W, V, T};

	if (keycode == ESC)
		exit_minirt(vars);
	else
	{
		i = 0;
		while (i < DIR_SIZE)
		{
			if (keycode == dir_to_move_key[i])
				move_camera(keycode, vars, dir_to_move_key);
			if (keycode == dir_to_rotate_key[i])
				rotate_camera(keycode, vars, dir_to_rotate_key);
			++i;
		}
	}
	return (0);
}
