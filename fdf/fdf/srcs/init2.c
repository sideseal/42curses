/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:33:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 01:39:19 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_draw(t_fdf *fdf)
{
	if (fdf->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (fdf->img == NULL)
		fdf_error("Error: mlx ");
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, \
		&fdf->line_len, &fdf->endian);
	if (fdf->addr == NULL)
		fdf_error("Error: mlx ");
}
