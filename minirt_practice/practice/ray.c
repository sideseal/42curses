/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 20:44:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "ray.h"
#include "hit.h"
#include "list.h"

t_ray	ray(t_point3 start, t_vec3 dir)
{
	t_ray	ray;

	ray.start = start;
	ray.dir = dir;
	return (ray);
}

t_color3	trace_ray(t_ray ray, t_obj_list *list, t_light light)
{
	t_hit		hit;
	double		dif;
	t_point3	dir_to_light;
	double		spec;
	t_point3	reflect_dir;

	hit = find_closest_collision(ray, list);
	if (hit.d >= 0.0f)
	{
		dir_to_light = vunit(vsub(light.pos, hit.point));
		dif = fmax(vdot(hit.normal, dir_to_light), 0.0f);

		reflect_dir = vsub(vmults(hit.normal, vdot(hit.normal, dir_to_light) * 2.0f), dir_to_light);
		spec = pow(fmax(vdot(vunit(vmults(ray.dir, -1.0f)), reflect_dir), 0.0f), hit.obj.alpha);

		t_vec3	diffuse = vmults(hit.obj.dif, dif);
		t_vec3	specular = vmults(vmults(hit.obj.spec, spec), hit.obj.ks);
		return (vadd(hit.obj.amb, vadd(diffuse, specular)));
	}
	return (color3(0.0f, 0.0f, 0.0f));
}
