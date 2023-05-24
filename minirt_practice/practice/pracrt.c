/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pracrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:43:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 18:56:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "init.h"
#include "pracrt.h"
#include "render.h"
#include "struct.h"

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx = init_mlx();
	img = init_img(mlx);
	render(mlx, img);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
