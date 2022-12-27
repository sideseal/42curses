/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/27 23:07:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf [file]\n", 1);
		return (1);
	}
	fdf = init_fdf(fdf);
	read_and_set(fdf, argv[1]);
	// draw section start
	draw_frame(fdf, -1);
	//draw_square(fdf);
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_hook, fdf);
	mlx_loop(fdf->mlx);
	// draw section end
	return (0);
}
