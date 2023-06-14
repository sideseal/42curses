/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:02 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:03 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_hit	hit_(double t_max)
{
	t_hit	this;

	this.t_min = EPSILON;
	this.t_max = t_max;
	return (this);
}

void	init_intersect_object(t_bool (*intersect_object[OBJECT_TYPE_SIZE])())
{
	intersect_object[CONE] = intersect_ray_cone;
	intersect_object[PLANE] = intersect_ray_plane;
	intersect_object[SPHERE] = intersect_ray_sphere;
	intersect_object[CYLINDER] = intersect_ray_cylinder;
	return ;
}

t_bool	hit_objects(t_object *objects, t_ray *ray, t_hit *hit)
{
	t_bool	is_hit;

	is_hit = FALSE;
	t_bool (*intersect_object[OBJECT_TYPE_SIZE])();
	init_intersect_object(intersect_object);
	while (objects)
	{
		if (intersect_object[objects->type](objects, ray, hit)) {
			is_hit = TRUE;
		}
		objects = objects->next;
	}
	return (is_hit);
}
