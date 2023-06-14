/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:52 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

static double	ray_disk_intersection(const t_cylinder *cylinder, t_ray *ray, \
t_hit *hit, t_point3 center)
{
	double	root;
	double	numerator;
	double	denominator;

	denominator = dot(ray->dir, cylinder->normal);
	if (fabs(denominator) < EPSILON)
		return (INVALID_ROOT);
	numerator = dot(sub(center, ray->origin), cylinder->normal);
	root = numerator / denominator;
	if (root < hit->t_min || hit->t_max < root)
		return (INVALID_ROOT);
	if (mag_sq(sub(ray_at(root, ray), center)) > cylinder->radius_sq)
		return (INVALID_ROOT);
	return (root);
}

t_bool	intersect_cylinder_base(t_object *object, t_ray *ray, t_hit *hit, \
enum e_component type)
{
	double				root;
	t_point3			center;
	const t_cylinder	*cylinder = object->element;

	center = cylinder->top_center;
	if (type == BASE)
		center = cylinder->base_center;
	root = ray_disk_intersection(cylinder, ray, hit, center);
	if (root == INVALID_ROOT)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = cylinder->normal;
	if (dot(ray->dir, hit->normal) > 0.0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
