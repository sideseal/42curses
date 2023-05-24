/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:16:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 19:58:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libvec.h"
#include "mlx.h"
#include "pracrt.h"
#include "render.h"
#include "stdio.h"

void	render(t_mlx mlx, t_img img)
{
	int	i;
	int	j;

	j = IMAGE_HEIGHT - 1;
	while (j >= 0)
	{
		printf("rendering... %.2f%%", \
				(float)(IMAGE_HEIGHT - j) / IMAGE_HEIGHT * 100);
		i = 0;
		while (i < IMAGE_WIDTH)
		{
			double	a = (double)(i) / (IMAGE_WIDTH - 1);
			double	b = 1 - (double)(j) / (IMAGE_HEIGHT - 1);
			my_mlx_pixel_put(&img, i, j, color3(a, b, 0.25));
			i++;
		}
		j--;
		printf("\033[1A\n");
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
}
