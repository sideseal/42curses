/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:34:01 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 21:45:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "utils.h"
#include "texture.h"

t_color3	get_clamped(t_texture *texture, int i, int j)
{
	double	r;
	double	g;
	double	b;

	i = clamp(i, 0, texture->width - 1);
	j = clamp(j, 0, texture->height - 1);

	r = texture->image[(i + texture->width * j) * texture->channels + 0] / 255.0f;
	g = texture->image[(i + texture->width * j) * texture->channels + 1] / 255.0f;
	b = texture->image[(i + texture->width * j) * texture->channels + 2] / 255.0f;

	return (color3(r, g, b));
}

t_color3	get_wrapped(t_texture *texture, int i, int j)
{
	double	r;
	double	g;
	double	b;

	i %= texture->width;
	j %= texture->height;

	if (i < 0)
		i += texture->width;
	if (j < 0)
		j += texture->height;

	r = texture->image[(i + texture->width * j) * texture->channels + 0] / 255.0f;
	g = texture->image[(i + texture->width * j) * texture->channels + 1] / 255.0f;
	b = texture->image[(i + texture->width * j) * texture->channels + 2] / 255.0f;

	return (color3(r, g, b));
}

t_point3	sample_point(t_texture *texture, t_vec2 *uv)
{
	t_vec2	xy;
	int		i;
	int		j;

	xy = v2sub(v2mult(*uv, vec2((double)texture->width, (double)texture->height)), vec2(0.5f, 0.5f));
	i = round(xy.x);
	j = round(xy.y);

	return (get_wrapped(texture, i, j));
}

t_point3	interpolate_bilinear(double dx, double dy, t_vec3 c00, t_vec3 c10, t_vec3 c01, t_vec3 c11)
{
	t_vec3	a;
	t_vec3	b;

	a = vadd(vmults(c00, (1.0f - dx)), vmults(c10, dx));
	b = vadd(vmults(c01, (1.0f - dx)), vmults(c11, dx));
	return (vadd(vmults(a, (1.0f - dy)), vmults(b, dy)));
}

t_point3	sample_linear(t_texture *texture, t_vec2 *uv)
{
	t_vec2	xy;
	int		i;
	int		j;
	double	dx;
	double	dy;

	xy = v2sub(v2mult(*uv, vec2((double)texture->width, (double)texture->height)), vec2(0.5f, 0.5f));
	i = (int)(floor(xy.x));
	j = (int)(floor(xy.y));
	dx = xy.x - (double)i;
	dy = xy.y - (double)j;
	return (interpolate_bilinear(dx, dy, get_wrapped(texture, i, j), get_wrapped(texture, i + 1, j), get_wrapped(texture, i, j + 1), get_wrapped(texture, i + 1, j + 1)));
}

t_texture	*generate_sample_texture_image(int width, int height, t_vec3 *sample_image)
{
	t_texture	*texture;
	double			*image;
	t_color3		color;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->width = width;
	texture->height = height;
	texture->channels = 3;
	image = malloc(sizeof(double) * width * height * 3);
	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			color = sample_image[i + j * width];
			image[(i + width * j) * 3 + 0] = color.x * 255;
			image[(i + width * j) * 3 + 1] = color.y * 255;
			image[(i + width * j) * 3 + 2] = color.z * 255;
		}
	texture->image = image;
	return (texture);
}

t_texture	*generate_texture_image(int width, int height, void *texture_image)
{
	t_texture			*texture;
	unsigned int		*data;
	unsigned int		pixel;
	double				*image;
	t_color3			color;
	int	bpp, size_l, endian;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	image = malloc(sizeof(double) * width * height * 3);
	if (!image)
		return (NULL);
	data = (unsigned int *)mlx_get_data_addr(texture_image, &bpp, &size_l, &endian);

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			pixel = data[size_l / (bpp / 8) * j + i];
			image[(i + width * j) * 3 + 0] = (pixel & (0xFF << 16)) >> 16;
			image[(i + width * j) * 3 + 1] = (pixel & (0xFF << 8)) >> 8;
			image[(i + width * j) * 3 + 2] = pixel & 0xFF;
		}

	texture->width = width;
	texture->height = height;
	texture->channels = 3;
	texture->image = image;
	return (texture);
}
