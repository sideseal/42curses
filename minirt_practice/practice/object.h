/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:07:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 21:28:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "texture.h"

typedef struct s_object
{
	t_color3	amb;
	t_color3	dif;
	t_color3	spec;
	double		alpha;
	double		ks;
	double		reflection;
	double		transparency;
//	t_color3	color;
	t_texture	*amb_texture;
	t_texture	*dif_texture;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_object	obj;
}	t_sphere;

typedef struct s_triangle
{
	t_point3	v0;
	t_point3	v1;
	t_point3	v2;
	t_object	obj;
	t_vec2		uv0;
	t_vec2		uv1;
	t_vec2		uv2;
}	t_triangle;

typedef struct s_square
{
	t_triangle	*triangle1;
	t_triangle	*triangle2;
	t_object	obj;
}	t_square;

t_sphere	*sphere(t_point3 center, double radius);
t_triangle	*triangle(t_point3 v0, t_point3 v1, t_point3 v2);
t_square	*square(t_point3 v0, t_point3 v1, t_point3 v2, t_point3 v3);

#endif
