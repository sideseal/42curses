/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:20:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 20:53:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_leaks(void)
{
	// 지우는거 잊지 말기
	system("leaks --list -- miniRT");
}

int	exit_hook(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	atexit(check_leaks);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		atexit(check_leaks);
		exit(0);
	}
	return (0);
}
