/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/05 12:41:35 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf [file]\n", 1);
		return (1);
	}
	fdf = init_fdf();
	read_file(fdf, argv[1]);
	draw_frame(fdf);
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
