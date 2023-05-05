/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:00:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 20:55:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray	ray(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	at;

	at = vadd_v(ray.origin, vmul_d(ray.direction, t));
	return (at);
}

t_ray	ray_primary(t_camera cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.direction = \
		vunit( \
			vsub_v( \
				vadd_v( \
					vadd_v( \
						cam.left_bottom, vmul_d(cam.horizontal, u) \
						), \
					vmul_d(cam.vertical, v) \
					), cam.origin) \
			);
	return (ray);
}

t_color3	ray_color(t_ray ray, t_object *world)
{
	double			t;
	t_vec3			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit(world, ray, &rec))
		return (vmul_d(vadd_v(rec.normal, color3(1, 1, 1)), 0.5));
	t = 0.5 * (ray.direction.y + 1.0);
	return (vadd_v \
			(vmul_d(color3(1, 1, 1), 1.0 - t), vmul_d(color3(0.5, 0.7, 1.0), t) \
			));
}
