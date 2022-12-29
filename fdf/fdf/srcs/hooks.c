/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:43:31 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/30 02:36:44 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

static void	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W)
		fdf->angle.alpha += -0.0314;
	if (keycode == KEY_S)
		fdf->angle.alpha += 0.0314;
	if (keycode == KEY_A)
		fdf->angle.beta += 0.0314;
	if (keycode == KEY_D)
		fdf->angle.beta += -0.0314;
	if (keycode == KEY_Q)
		fdf->angle.gamma += -0.0314;
	if (keycode == KEY_E)
		fdf->angle.gamma += 0.0314;
}

static void	move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
	{
		fdf->offset.y -= (2 + (int)fdf->offset.zoom);
	}
	if (keycode == KEY_DOWN)
	{
		fdf->offset.y += (2 + (int)fdf->offset.zoom);
	}
	if (keycode == KEY_LEFT)
	{
		fdf->offset.x -= (2 + (int)fdf->offset.zoom);
	}
	if (keycode == KEY_RIGHT)
	{
		fdf->offset.x += (2 + (int)fdf->offset.zoom);
	}
}

static void	zoom_or_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ZOOM_IN)
	{
		if (fdf->offset.zoom < 100)
			fdf->offset.zoom *= 1.2;
	}
	if (keycode == KEY_ZOOM_OUT)
	{
		if (fdf->offset.zoom > 0)
			fdf->offset.zoom /= 1.2;
		fdf->offset.y = 0;
		fdf->offset.x = 0;
	}
	if (keycode == KEY_Z_UP)
	{
		if (fdf->offset.zoom < 100)
			fdf->offset.z *= 1.2;
	}
	if (keycode == KEY_Z_DOWN)
	{
		if (fdf->offset.z > 0)
			fdf->offset.z /= 1.2;
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A \
	|| keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		rotate(keycode, fdf);
	if (keycode == KEY_UP || keycode == KEY_DOWN \
	|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(keycode, fdf);
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT \
	|| keycode == KEY_Z_UP || keycode == KEY_Z_DOWN)
		zoom_or_translate(keycode, fdf);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	draw_frame(fdf, keycode);
	return (0);
}
