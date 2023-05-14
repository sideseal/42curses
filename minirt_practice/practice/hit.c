/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 23:32:39 by gychoi           ###   ########.fr       */
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

int	check_ray_collision_triangle(t_ray ray, t_triangle *triangle, t_point3 *point, t_point3 *face_normal, double *t, double *u, double *v)
{
	*face_normal = vunit(vcross(vsub(triangle->v1, triangle->v0), vsub(triangle->v2, triangle->v0))); // division zero 주의
	if (vdot(vmults(ray.dir, 1), *face_normal) < 0.0f)
		return (FALSE);
	if (fabs(vdot(ray.dir, *face_normal)) < EPSILON)
		return (FALSE);
	*t = (vdot(triangle->v0, *face_normal) - vdot(ray.start, *face_normal)) / (vdot(ray.dir, *face_normal));
	if (*t < 0.0f) // 광선이 반대 방향으로 나가는 경우
		return (FALSE);
	*point = vadd(ray.start, vmults(ray.dir, *t));
	return (TRUE);
}

t_hit	intersect_ray_collision_triangle(t_ray ray, t_triangle *triangle)
{
	t_hit		hitobj;
	t_point3	point;
	t_point3	face_normal;
	double		t;
	double		u;
	double		v;

	point = point3(0.0f, 0.0f, 0.0f);
	face_normal = point3(0.0f, 0.0f, 0.0f);
	hitobj = hit(-1.0f, point3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f));
	if (check_ray_collision_triangle(ray, triangle, &point, &face_normal, &t, &u, &v))
	{
		hitobj.d = t;
		hitobj.point = point;
		hitobj.normal = face_normal;
		printf("%f, %f, %f\n", hitobj.point.x, hitobj.point.y, hitobj.point.z);
	}
	return (hitobj);
}

t_hit	find_closest_collision(t_ray ray, t_obj_list *list)
{
	t_hit		closest_hit;
	t_hit		hitobj;
	t_sphere	*sphere;
	t_triangle	*triangle;
	double		closest;

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
			hitobj = intersect_ray_collision_triangle(ray, triangle);
			if (hitobj.d >= 0.0f)
			{
				if (hitobj.d < closest)
				{
					closest = hitobj.d;
					closest_hit = hitobj;
					closest_hit.obj = triangle->obj;
				}
			}
		}
		list = list->next;
	}
	return (closest_hit);
}

