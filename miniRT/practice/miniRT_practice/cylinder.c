/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:44 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:46 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, double radius, \
double height)
{
	t_cylinder	*this;

	this = (t_cylinder *)malloc((sizeof(t_cylinder)));
	if (this == NULL)
		return (NULL);
	this->normal = norm(normal);
	this->height = height;
	this->base_center = center;
	this->top_center = add(this->base_center, scl_mul(this->height, \
	this->normal));
	this->radius = radius;
	this->radius_sq = radius * radius;
	return (this);
}

t_bool	intersect_ray_cylinder(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cylinder_base(object, ray, hit, TOP);
	is_inter += intersect_cylinder_base(object, ray, hit, BASE);
	is_inter += intersect_cylinder_surface(object, ray, hit);
	return (is_inter);
}
