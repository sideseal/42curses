/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:05:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 20:27:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "object.h"

t_object	object(t_color3 color)
{
	t_object	obj;

	obj.amb = color;
	obj.dif = color;
	obj.spec = color;
	obj.alpha = 0.0f;
	obj.ks = 1.0f;
	obj.reflection = 0.0f;
	obj.transparancy = 0.0f;
	obj.color = color;
	obj.amb_texture = NULL;
	return (obj);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	sphere->obj = object(color3(0.5f, 0.5f, 0.5f));
	return (sphere);
}

t_triangle	*triangle(t_point3 v0, t_point3 v1, t_point3 v2)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (NULL);
	triangle->v0 = v0;
	triangle->v1 = v1;
	triangle->v2 = v2;
	triangle->obj = object(color3(0.5f, 0.5f, 0.5f));
	triangle->uv0 = vec2(0.0f, 0.0f);
	triangle->uv1 = vec2(0.0f, 0.0f);
	triangle->uv2 = vec2(0.0f, 0.0f);
	return (triangle);
}

t_square	*square(t_point3 v0, t_point3 v1, t_point3 v2, t_point3 v3 , t_tpoints *texture)
{
	t_square	*square;

	square = malloc(sizeof(t_triangle) * 2);
	if (!square)
		return (NULL);
	square->triangle1 = triangle(v0, v1, v2);
	square->triangle2 = triangle(v0, v2, v3);
	square->obj = object(color3(0.5f, 0.5f, 0.5f));
	if (texture)
	{
		square->triangle1->uv0 = texture->uv0;
		square->triangle1->uv1 = texture->uv1;
		square->triangle1->uv2 = texture->uv2;
		square->triangle2->uv0 = texture->uv0;
		square->triangle2->uv1 = texture->uv2;
		square->triangle2->uv2 = texture->uv3;
	}
	return (square);
}
