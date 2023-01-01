/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:43:31 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 22:06:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
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
	if (keycode == KEY_ISO)
		isometric(fdf);
	if (keycode == KEY_OTH)
		orthographic(fdf);
	if (keycode == KEY_RST)
		reset_translation(fdf);
}

static void	move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->offset.y -= (2 + (int)fdf->offset.zoom);
	if (keycode == KEY_DOWN)
		fdf->offset.y += (2 + (int)fdf->offset.zoom);
	if (keycode == KEY_LEFT)
		fdf->offset.x -= (2 + (int)fdf->offset.zoom);
	if (keycode == KEY_RIGHT)
		fdf->offset.x += (2 + (int)fdf->offset.zoom);
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
		if (fdf->offset.z < 100)
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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A \
	|| keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E \
	|| keycode == KEY_ISO || keycode == KEY_OTH || keycode == KEY_RST)
		rotate(keycode, fdf);
	if (keycode == KEY_UP || keycode == KEY_DOWN \
	|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(keycode, fdf);
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT \
	|| keycode == KEY_Z_UP || keycode == KEY_Z_DOWN)
		zoom_or_translate(keycode, fdf);
	draw_frame(fdf);
	return (0);
}
