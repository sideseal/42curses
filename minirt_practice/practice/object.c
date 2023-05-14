/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:05:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 21:46:52 by gychoi           ###   ########.fr       */
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
	return (obj);
}

t_sphere	*sphere(t_point3 center, double radius, t_color3 color)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	sphere->obj = object(color);
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
	return (triangle);
}
