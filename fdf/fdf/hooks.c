/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:43:31 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/27 23:19:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == KEY_W)
		fdf->angle.alpha += 0.0314;
	if (keycode == KEY_S)
		fdf->angle.alpha += -0.0314;
	if (keycode == KEY_A)
		fdf->angle.beta += -0.0314;
	if (keycode == KEY_D)
		fdf->angle.beta += 0.0314;
	if (keycode == KEY_Q)
		fdf->angle.gamma += -0.0314;
	if (keycode == KEY_E)
		fdf->angle.gamma += 0.0314;
	if (keycode == KEY_UP)
		fdf->offset.y -= 2;
	if (keycode == KEY_DOWN)
		fdf->offset.y += 2;
	if (keycode == KEY_LEFT)
		fdf->offset.x -= 2;
	if (keycode == KEY_RIGHT)
		fdf->offset.x += 2;
	if (keycode == KEY_ZOOM_IN)
		fdf->offset.zoom *= 1.2;
	if (keycode == KEY_ZOOM_OUT)
	{
		if (fdf->offset.zoom > 0)
			fdf->offset.zoom /= 1.2;
	}
	if (keycode == KEY_Z_UP)
		fdf->offset.z *= 1.2;
	if (keycode == KEY_Z_DOWN)
	{
		if (fdf->offset.z > 0)
			fdf->offset.z /= 1.2;
	}
	draw_frame(fdf, keycode);
	return (0);
}

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}
