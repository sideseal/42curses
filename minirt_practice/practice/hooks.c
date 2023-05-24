/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:53:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 17:58:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
