/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/13 23:10:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "ray.h"
#include "hit.h"

t_ray	ray(t_point3 start, t_vec3 dir)
{
	t_ray	ray;

	ray.start = start;
	ray.dir = dir;
	return (ray);
}

t_color3	trace_ray(t_ray ray, t_sphere *sphere, t_light light)
{
	t_hit		hit;
	double		diff;
	t_point3	dir_to_light;
	double		specular;
	t_point3	reflect_dir;

	hit = intersect_ray_collision(ray, sphere);
	if (hit.d < 0.0f)
		return (color3(0, 0, 0));
	else
	{
		dir_to_light = vunit(vsub(light.pos, hit.point));
		diff = vdot(hit.normal, dir_to_light);
		if (0.0f > diff)
			diff = 0.0f;
		return (vmults(sphere->diff, diff));
	}
}
