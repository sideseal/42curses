/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/29 21:34:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		keycode;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf [file]\n", 1);
		return (1);
	}
	keycode = -1;
	fdf = init_fdf();
	read_and_set(fdf, argv[1]);
	draw_frame(fdf, keycode);
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
