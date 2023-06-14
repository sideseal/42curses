/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:05 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:06 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_sphere	*sphere_(t_point3 center, double radius)
{
	t_sphere	*this;

	this = (t_sphere *)malloc(sizeof(t_sphere));
	if (this == NULL)
		return (NULL);
	this->center = center;
	this->radius = radius;
	this->radius_sq = radius * radius;
	return (this);
}

static t_coefficient	get_coefficient(const t_sphere *sphere, t_ray *ray)
{
	t_coefficient	coef;
	const t_vec3	co = sub(ray->origin, sphere->center);

	coef.a = mag_sq(ray->dir);
	coef.b = dot(co, ray->dir);
	coef.c = mag_sq(co) - sphere->radius_sq;
	return (coef);
}

t_bool	intersect_ray_sphere(t_object *object, t_ray *ray, t_hit *hit)
{
	const t_sphere		*sphere = object->element;
	const t_coefficient	coef = get_coefficient(sphere, ray);
	const double		d = coef.b * coef.b - coef.a * coef.c;
	const double		sqrtd = sqrt(d);
	double				root;

	if (d < 0.0)
		return (FALSE);
	root = (-coef.b - sqrtd) / coef.a;
	if (root < hit->t_min || hit->t_max < root)
	{
		root = (-coef.b + sqrtd) / coef.a;
		if (root < hit->t_min || hit->t_max < root)
			return (FALSE);
	}
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = norm(sub(hit->point, sphere->center));
	if (dot(ray->dir, hit->normal) > 0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
