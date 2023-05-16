/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:34:21 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 22:06:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct s_tpoints
{
	t_vec2	uv0;
	t_vec2	uv1;
	t_vec2	uv2;
	t_vec2	uv3;
}	t_tpoints;

typedef struct s_texture
{
	int			width;
	int			height;
	int			channels;
	double		*image;
}	t_texture;

t_color3	get_clamped(t_texture *texture, int i, int j);
t_color3	get_wrapped(t_texture *texture, int i, int j);
t_point3	sample_point(t_texture *texture, t_vec2 *uv);
t_texture	*generate_sample_texture_image(int width, int height, t_vec3 *sample_image);

#endif
