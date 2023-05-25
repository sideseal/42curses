/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:48:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 21:59:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "object.h"
#include "ray.h"

t_ray	ray_primary(t_camera cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.dir = vunit(vsub(\
				vadd(\
					vadd(cam.left_bottom, vmults(cam.horizontal, u)),\
					vmults(cam.vertical, v)\
					),\
				cam.origin)\
			);
	return (ray);
}

t_color3	ray_color(t_ray r, t_sphere sp)
{
	double			t;
	t_vec3			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	t = hit_sphere(sp, r, rec);
	if (t > 0.0)
		return (vmults(vadd(rec.normal, color3(1.0, 1.0, 1.0)), 0.5));
	t = 0.5 * (r.dir.y + 1.0);
	return (vadd(vmults(color3(1, 1, 1), 1.0 - t), vmults(color3(0.5, 0.7, 1.0), t)));
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	ray_at;

	ray_at = vadd(ray.origin, vmults(ray.dir, t));
	return (ray_at);
}

t_ray	ray(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir; // vunit?
	return (ray);
}
