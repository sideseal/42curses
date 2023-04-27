/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:42:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/27 20:40:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_vars	vars;
	t_data	image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello");
	image.img = mlx_new_image(vars.mlx, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
			my_mlx_pixel_put(&image, i, j, 0x00000000);
	}
	my_mlx_pixel_put(&image, 250, 250, 0x0000FFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
