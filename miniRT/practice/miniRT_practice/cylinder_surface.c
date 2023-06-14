/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:56 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:57 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

static t_coefficient	get_coefficient(const t_cylinder *cylinder, t_ray *ray)
{
	t_coefficient	coef;
	const t_vec3	w = sub(ray->origin, cylinder->base_center);
	const double	v_dot_h = dot(ray->dir, cylinder->normal);
	const double	w_dot_h = dot(w, cylinder->normal);

	coef.a = mag_sq(ray->dir) - v_dot_h * v_dot_h;
	coef.b = dot(ray->dir, w) - v_dot_h * w_dot_h;
	coef.c = mag_sq(w) - w_dot_h * w_dot_h - cylinder->radius_sq;
	return (coef);
}

static double	ray_surface_intersection(const t_cylinder *cylinder, \
t_ray *ray, t_hit *hit)
{
	const t_coefficient	coef = get_coefficient(cylinder, ray);
	const double		d = coef.b * coef.b - coef.a * coef.c;
	double				root;
	double				height;
	t_vec3				cp;

	if (d < 0.0)
		return (INVALID_ROOT);
	root = (-coef.b - sqrt(d)) / coef.a;
	if (root < hit->t_min || hit->t_max < root)
	{
		root = (-coef.b + sqrt(d)) / coef.a;
		if (root < hit->t_min || hit->t_max < root)
			return (INVALID_ROOT);
	}
	cp = sub(ray_at(root, ray), cylinder->base_center);
	height = dot(cp, cylinder->normal);
	if (height < 0 || cylinder->height < height)
		return (INVALID_ROOT);
	return (root);
}

t_bool	intersect_cylinder_surface(t_object *object, t_ray *ray, t_hit *hit)
{
	const t_cylinder	*cylinder = object->element;
	const double		root = ray_surface_intersection(cylinder, ray, hit);
	t_vec3				cp;

	if (root == INVALID_ROOT)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	cp = sub(hit->point, cylinder->base_center);
	hit->normal = norm(sub(cp, scl_mul(dot(cp, cylinder->normal), \
	cylinder->normal)));
	if (dot(ray->dir, hit->normal) > 0.0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
