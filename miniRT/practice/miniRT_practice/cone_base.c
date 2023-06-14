/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:32 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:33 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

static double	ray_disk_intersection(const t_cone *cone, t_ray *ray, \
t_hit *hit)
{
	double	root;
	double	numerator;
	double	denominator;

	denominator = dot(ray->dir, cone->h_normal);
	if (fabs(denominator) < EPSILON)
		return (INVALID_ROOT);
	numerator = dot(sub(cone->base_center, ray->origin), cone->h_normal);
	root = numerator / denominator;
	if (root < hit->t_min || hit->t_max < root)
		return (INVALID_ROOT);
	if (mag_sq(sub(ray_at(root, ray), cone->base_center)) > cone->radius_sq)
		return (INVALID_ROOT);
	return (root);
}

t_bool	intersect_cone_base(t_object *object, t_ray *ray, t_hit *hit)
{
	const t_cone	*cone = object->element;
	const double	root = ray_disk_intersection(cone, ray, hit);

	if (root == INVALID_ROOT)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = cone->h_normal;
	if (dot(ray->dir, hit->normal) > 0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
