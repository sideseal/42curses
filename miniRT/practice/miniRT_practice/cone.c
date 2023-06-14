/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:24 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:26 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_cone	*cone_(t_point3 center, t_vec3 normal, double radius, double height)
{
	t_cone	*this;

	this = (t_cone *)malloc((sizeof(t_cone)));
	if (this == NULL)
		return (NULL);
	this->normal = norm(normal);
	this->base_center = center;
	this->tip_center = add(this->base_center, scl_mul(height, this->normal));
	this->h_dir = sub(this->base_center, this->tip_center);
	this->h_normal = norm(this->h_dir);
	this->height = height;
	this->radius = radius;
	this->radius_sq = radius * radius;
	return (this);
}

t_bool	intersect_ray_cone(t_object *object, t_ray *ray, t_hit *hit)
{
	t_bool	is_inter;

	is_inter = FALSE;
	is_inter += intersect_cone_surface(object, ray, hit);
	is_inter += intersect_cone_base(object, ray, hit);
	return (is_inter);
}
