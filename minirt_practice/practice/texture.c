/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:34:01 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 17:33:21 by gychoi           ###   ########.fr       */
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
	t_vec2	temp;

	temp = *uv;
	xy = v2sub(v2mult(temp, vec2((double)texture->width, (double)texture->height)), vec2(0.5f, 0.5f));
	i = round(xy.x);
	j = round(xy.y);

	return (get_clamped(texture, i, j));
}

t_point3	sample_linear(t_vec2 *uv)
{
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

