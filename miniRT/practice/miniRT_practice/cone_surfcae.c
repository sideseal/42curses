/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_surfcae.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:37 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:39 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

static t_coefficient	get_coefficient(const t_cone *cone, t_ray *ray, \
t_vec3 h_hat)
{
	t_coefficient	coef;
	const t_vec3	w = sub(ray->origin, cone->tip_center);
	const double	m = cone->radius_sq / mag_sq(cone->h_dir);
	const double	v_dot_h = dot(ray->dir, h_hat);
	const double	w_dot_h = dot(w, h_hat);

	coef.a = mag_sq(ray->dir) - (m + 1) * v_dot_h * v_dot_h;
	coef.b = dot(ray->dir, w) - (m + 1) * v_dot_h * w_dot_h;
	coef.c = mag_sq(w) - (m + 1) * w_dot_h * w_dot_h;
	return (coef);
}

static double	ray_surface_intersection(const t_cone *cone, t_ray *ray, \
t_hit *hit, t_vec3 h_hat)
{
	const t_coefficient	coef = get_coefficient(cone, ray, h_hat);
	const double		d = coef.b * coef.b - coef.a * coef.c;
	double				root;
	double				height;
	t_vec3				hp;

	if (d < 0.0)
		return (INVALID_ROOT);
	root = (-coef.b - sqrt(d)) / coef.a;
	if (root < hit->t_min || hit->t_max < root)
	{
		root = (-coef.b + sqrt(d)) / coef.a;
		if (root < hit->t_min || hit->t_max < root)
			return (INVALID_ROOT);
	}
	hp = sub(ray_at(root, ray), cone->tip_center);
	height = dot(hp, h_hat);
	if (height < 0 || cone->height < height)
		return (INVALID_ROOT);
	return (root);
}

t_vec3	interface_normal(const t_cone *cone, t_point3 point)
{
	double			cos_theta;
	double			hypotenuse;
	t_vec3			normal;
	const t_vec3	hp = sub(point, cone->tip_center);

	cos_theta = mag(cone->h_dir) / sqrt(cone->radius_sq + mag_sq(cone->h_dir));
	hypotenuse = mag(hp) / cos_theta;
	normal = sub(point, add(cone->tip_center, \
	scl_mul(hypotenuse, cone->h_normal)));
	return (normal);
}

t_bool	intersect_cone_surface(t_object *object, t_ray *ray, t_hit *hit)
{
	const t_cone	*cone = object->element;
	const double	root = ray_surface_intersection(cone, ray, hit, \
	cone->h_normal);

	if (root == INVALID_ROOT)
		return (FALSE);
	hit->t = root;
	hit->t_max = hit->t;
	hit->point = ray_at(hit->t, ray);
	hit->normal = interface_normal(cone, hit->point);
	if (dot(ray->dir, hit->normal) > 0)
		hit->normal = scl_mul(-1, hit->normal);
	hit->albedo = object->albedo;
	return (TRUE);
}
