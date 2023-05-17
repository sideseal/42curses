/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 22:52:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "ray.h"
#include "hit.h"
#include "list.h"
#include "texture.h"

t_ray	ray(t_point3 start, t_vec3 dir)
{
	t_ray	ray;

	ray.start = start;
	ray.dir = dir;
	return (ray);
}

t_color3	trace_ray(t_ray pixel_ray, t_obj_list *list, t_light light, int recursive_level)
{
	t_hit		hit;
	double		dif;
	t_point3	dir_to_light;
	double		spec;
	t_point3	reflect_dir;
	t_ray		shadow_ray;
	t_color3	point_color;
	t_color3	final_color;
	t_point3	reflected_dir;
	t_ray		reflection_ray;

	if (recursive_level < 0)
		return (color3(0.0f, 0.0f, 0.0f));
	hit = find_closest_collision(pixel_ray, list);
	if (hit.d >= 0.0f)
	{
		final_color = color3(0.0f, 0.0f, 0.0f);

		if (hit.obj.amb_texture)
			point_color = vmult(hit.obj.amb, sample_linear(hit.obj.amb_texture, &hit.uv));
		else
			point_color = hit.obj.amb;
		dir_to_light = vunit(vsub(light.pos, hit.point));
//		shadow_ray = ray(vadd(hit.point, vmults(dir_to_light, EPSILON)), dir_to_light);
//
//		if (find_closest_collision(shadow_ray, list).d < 0.0f || find_closest_collision(shadow_ray, list).d > vlen(vsub(light.pos, hit.point)))
//		{
			dif = fmax(vdot(hit.normal, dir_to_light), 0.0f);
			reflect_dir = vsub(vmults(hit.normal, vdot(hit.normal, dir_to_light) * 2.0f), dir_to_light);
			spec = pow(fmax(vdot(vunit(vmults(pixel_ray.dir, -1.0f)), reflect_dir), 0.0f), hit.obj.alpha);

			t_vec3	diffuse = vmults(hit.obj.dif, dif);
			t_vec3	specular = vmults(vmults(hit.obj.spec, spec), hit.obj.ks);

			if (hit.obj.dif_texture)
				point_color = vadd(point_color, vmult(diffuse, sample_linear(hit.obj.dif_texture, &hit.uv)));
			else
				point_color = vadd(point_color, diffuse);
			point_color = vadd(point_color, specular);

			final_color = vadd(final_color, vmults(point_color, (1.0f - hit.obj.reflection - hit.obj.transparency)));
			
			if (hit.obj.reflection > 0.0f)
			{
				reflected_dir = vunit(vadd(vmults(vmults(hit.normal, 2.0f), vdot(vmults(pixel_ray.dir, -1.0f), hit.normal)), pixel_ray.dir));
				reflection_ray = ray(vadd(hit.point, vmults(reflected_dir, EPSILON)), reflected_dir);
				final_color = vadd(final_color, vmults(trace_ray(reflection_ray, list, light, recursive_level - 1), hit.obj.reflection));
			}
			if (hit.obj.transparency > 0.0f)
			{
			}
//		}
		return (final_color);
	}
	return (color3(0.0f, 0.0f, 0.0f));
}

t_color3	trace_ray_2x2(t_vec3 eye_pos, t_color3 pixel_pos, double dx, int recursive_level, t_obj_list *list, t_light light)
{
	t_ray		pixel_ray;
	t_ray		sub_ray;
	double		subdx;
	t_color3	pixel_color;
	t_vec3		sub_pos;

	if (recursive_level == 0)
	{
		pixel_ray = ray(pixel_pos, vunit(vsub(pixel_pos, eye_pos)));
		return (trace_ray(pixel_ray, list, light, 5));
	}
	subdx = 0.5f * dx;
	pixel_color = color3(0.0f, 0.0f, 0.0f);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 2; i++)
		{
			sub_pos = vec3(pixel_pos.x + (double)i * subdx, pixel_pos.y + (double)j * subdx, pixel_pos.z);
			sub_ray = ray(sub_pos, vunit(vsub(sub_pos, eye_pos)));
			pixel_color = vadd(pixel_color, trace_ray_2x2(eye_pos, sub_pos, subdx, recursive_level - 1, list, light));
		}
	return (vmults(pixel_color, 0.25f));
}
