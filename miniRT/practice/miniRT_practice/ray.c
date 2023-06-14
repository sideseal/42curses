/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:46 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:49 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_ray ray_(t_point3 origin, t_vec3 dir)
{
	t_ray this;

	this.origin = origin;
	this.dir = norm(dir);
	return (this);
}

t_vec3	ray_at(double t, t_ray *ray)
{
	t_vec3 this;

	this = add(ray->origin, scl_mul(t, ray->dir));
	return (this);
}

t_ray primary_ray(t_camera *cam, t_vec2 xy)
{
	t_ray			this;
	const t_vec3	ai = scl_mul(xy.x, cam->ai);
	const t_vec3	bj = scl_mul(xy.y, cam->bj);

	this.origin = cam->origin;
	this.dir = norm(sub(add(add(cam->lower_left_corner, ai), bj), cam->origin));
	return (this);
}

int	ray_color(t_scene *scene)
{
	double		t;
	t_color3	color;

	scene->hit = hit_(INFINITY);
	if (hit_objects(scene->objects, &scene->ray, &scene->hit))
		color = phong_lighting(scene);
	else
	{
		t = 0.5 * (scene->ray.dir.bj + 1.0);
		color = add(scl_mul(1.0 - t, color3_(1.0, 1.0, 1.0)), scl_mul(t, color3_(0.5, 0.7, 1.0)));
	}
	return (create_trgb(color));
}

