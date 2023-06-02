/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:02:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 17:00:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "typedef.h"

struct s_object
{
	void			*element;
	void			*next;
	t_color3		albedo;
	t_object_type	type;
};

struct s_ray
{
	t_vec3		dir;
	t_point3	origin;
};

struct s_hit
{
	double		t;
	double		t_min;
	double		t_max;
	t_vec3		normal;
	t_point3	point;
	t_color3	albedo;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_camera
{
	double		viewport_w;
	double		viewport_h;
	t_point3	origin;
	t_point3	lower_left_corner;
	t_vec3		ai;
	t_vec3		bj;
};

struct s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_ray		ray;
	t_hit		hit;
	t_color3	ambient;
	t_object	*lights;
	t_object	*objects;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_scene		scene;
};

#endif
