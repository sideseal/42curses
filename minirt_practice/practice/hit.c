/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 21:56:51 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "hit.h"

t_hit	hit(double d, t_point3 point, t_vec3 normal)
{
	t_hit	hit;

	hit.d = d;
	hit.point = point;
	hit.normal = normal;
	return (hit);
}

t_hit	intersect_ray_collision_sphere(t_ray ray, t_sphere *sphere)
{
	t_hit	hitobj;
	double	b;
	double	c;
	double	nabla;
	double	d1;
	double	d2;

	hitobj = hit(-1.0f, point3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f));
	b = 2.0f * vdot(ray.dir, vsub(ray.start, sphere->center));
	c = vdot(vsub(ray.start, sphere->center), vsub(ray.start, sphere->center)) - sphere->radius * sphere->radius;
	nabla = b * b / 4.0f - c;

	if (nabla >= 0.0)
	{
		d1 = -b / 2.0 + sqrt(nabla);
		d2 = -b / 2.0 - sqrt(nabla);
		hitobj.d = d2;
		if (d1 < d2)
			hitobj.d = d1;
		hitobj.point = vadd(ray.start, vmults(ray.dir, hitobj.d));
		hitobj.normal = vunit(vsub(hitobj.point, sphere->center));
	}
	return (hitobj);
}

t_hit	intersect_ray_collision_triangle(t_ray ray, t_triangle *triangle, t_point3 *point, t_point3 *face_normal, double *t, double *u, double *v)
{

}

t_hit	find_closest_collision(t_ray ray, t_obj_list *list)
{
	t_hit		closest_hit;
	t_hit		hitobj;
	t_sphere	*sphere;
	t_triangle	*triangle;
	t_point3	point;
	t_point3	face_normal;
	double		closest;
	double		t;
	double		u;
	double		v;

	closest_hit = hit(-1.0f, point3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f));
	closest = INFINITY;
	while (list)
	{
		if (list->type == SP)
		{
			sphere = list->element;
			hitobj = intersect_ray_collision_sphere(ray, sphere);
			if (hitobj.d >= 0.0f)
			{
				if (hitobj.d < closest)
				{
					closest = hitobj.d;
					closest_hit = hitobj;
					closest_hit.obj = sphere->obj;
				}
			}
		}
		if (list->type == TR)
		{
			triangle = list->element;
			//hitobj = intersect_ray_collision_triangle(ray, triangle, &point, &face_normal, &t, &u, &v);
		}
		list = list->next;
	}
	return (closest_hit);
}

