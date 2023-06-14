/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:38 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:39 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_plane	*plane_(t_point3 point, t_vec3 normal)
{
	t_plane	*this;

	this = (t_plane *)malloc(sizeof(t_plane));
	if (this == NULL)
		return (NULL);
	this->point = point;
	this->normal = normal;
	return (this);
}

t_bool	intersect_ray_plane(t_object *object, t_ray *ray, t_hit *hit)
{
	double			root;
	const t_plane	*plane = object->element;
	const t_vec3	p0l0 = sub(plane->point, ray->origin);
	const double	numerator = dot(p0l0, plane->normal);
	const double	denominator = dot(plane->normal, ray->dir);

	if (fabs(denominator) <= EPSILON)
		return (FALSE);
	root = numerator / denominator;
	if (root < hit->t_min || hit->t_max < root)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = plane->normal;
	if (dot(ray->dir, hit->normal) > 0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
