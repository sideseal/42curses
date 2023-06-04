/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redef_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:56:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 21:46:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*rt_mlx_get_data_addr(t_data *data)
{
	char	*ret;
	void	*img;
	int		*bpp;
	int		*line_len;
	int		*endian;

	img = data->img.img;
	bpp = &data->img.bpp;
	line_len = &data->img.line_len;
	endian = &data->img.endian;
	ret = mlx_get_data_addr(img, bpp, line_len, endian);
	if (ret == NULL)
		print_error("mlx_get_data_addr ", data);
	return (ret);
}

void	*rt_mlx_init(t_data *data)
{
	void	*ret;

	ret = mlx_init();
	if (ret == NULL)
		print_error("mlx_init ", data);
	return (ret);
}

void	*rt_mlx_new_image(t_data *data, int width, int height)
{
	void	*ret;

	ret = mlx_new_image(data->mlx, width, height);
	if (ret == NULL)
		print_error("mlx_new_image ", data);
	return (ret);
}

void	*rt_mlx_new_window(t_data *data, int sx, int sy, char *title)
{
	void	*ret;

	ret = mlx_new_window(data->mlx, sx, sy, title);
	if (ret == NULL)
		print_error("mlx_new_window ", data);
	return (ret);
}

void	rt_mlx_pixel_put(t_img *img, int x, int y, t_color3 color)
{
	char	*dst;
	int		pixel;

	pixel = (int)(255.999 * color.r) << 16 | \
			(int)(255.999 * color.g) << 8 | \
			(int)(255.999 * color.b);
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = pixel;
}
