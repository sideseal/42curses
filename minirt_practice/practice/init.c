/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:57:33 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 19:45:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, IMAGE_WIDTH, IMAGE_HEIGHT, "test");
	return (mlx);
}

t_img	init_img(t_mlx mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
	return (img);
}
