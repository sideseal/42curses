/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:03:50 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 21:40:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	_free_mlx(t_data *data)
{
//	free(data->win);
//	free(data->img.img);
//	free(data->img.addr);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_del(data->mlx);
}

void	free_struct(t_data *data)
{
	_free_mlx(data);
	// free_objects
	free(data);
}
