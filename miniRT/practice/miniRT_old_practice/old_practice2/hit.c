/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/18 20:57:37 by gychoi           ###   ########.fr       */
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
		hitobj.d = fmin(d1, d2);
		if (hitobj.d < 0.0f)
			hitobj.d = fmax(d1, d2);
		hitobj.point = vadd(ray.start, vmults(ray.dir, hitobj.d));
		hitobj.normal = vunit(vsub(hitobj.point, sphere->center));
	}
	return (hitobj);
}

int	check_ray_collision_triangle(t_ray ray, t_triangle *triangle, t_point3 *point, t_point3 *face_normal, double *t, double *u, double *v)
{
	t_vec3	cross0;
	t_vec3	cross1;
	t_vec3	cross2;
	double	area0;
	double	area1;
	double	area2;
	double	area_sum;

	// division zero 주의
	*face_normal = vunit(vcross(vsub(triangle->v1, triangle->v0), vsub(triangle->v2, triangle->v0)));
	if (vdot(vmults(ray.dir, -1), *face_normal) < 0.0f)
		return (FALSE);
	if (fabs(vdot(ray.dir, *face_normal)) < EPSILON)
		return (FALSE);
	*t = (vdot(triangle->v0, *face_normal) - vdot(ray.start, *face_normal)) / (vdot(ray.dir, *face_normal));
	if (*t < 0.0f)
		return (FALSE);
	*point = vadd(ray.start, vmults(ray.dir, *t));
	cross0 = vcross(vsub(*point, triangle->v2), vsub(triangle->v1, triangle->v2));
	cross1 = vcross(vsub(*point, triangle->v0), vsub(triangle->v2, triangle->v0));
	cross2 = vcross(vsub(triangle->v1, triangle->v0), vsub(*point, triangle->v0));
	if (vdot(cross0, *face_normal) < 0.0f)
		return (FALSE);
	if (vdot(cross1, *face_normal) < 0.0f)
		return (FALSE);
	if (vdot(cross2, *face_normal) < 0.0f)
		return (FALSE);
	area0 = vlen(cross0) * 0.5f;
	area1 = vlen(cross1) * 0.5f;
	area2 = vlen(cross2) * 0.5f;
	area_sum = area0 + area1 + area2;

	*u = area0 / area_sum;
	*v = area1 / area_sum;

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
	t = 0.0f;
	u = 0.0f;
	v = 0.0f;
	hitobj = hit(-1.0f, point3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f));
	if (check_ray_collision_triangle(ray, triangle, &point, &face_normal, &t, &u, &v))
	{
		hitobj.d = t;
		hitobj.point = point;
		hitobj.normal = face_normal;
		hitobj.uv = v2add(v2add(v2mults(triangle->uv0, u), v2mults(triangle->uv1, v)), v2mults(triangle->uv2, (1.0f - u - v)));
		//printf("%f, %f, %f\n", hitobj.normal.x, hitobj.normal.y, hitobj.normal.z);
	}
	return (hitobj);
}

t_hit	intersect_ray_collision_square(t_ray ray, t_square *square)
{
	t_hit	hit1;
	t_hit	hit2;

	hit1 = intersect_ray_collision_triangle(ray, square->triangle1);
	hit2 = intersect_ray_collision_triangle(ray, square->triangle2);
	if (hit1.d >= 0.0f && hit2.d >= 0.0f)
	{
		if (hit1.d < hit2.d)
			return (hit1);
		else
			return (hit2);
	}
	else if (hit1.d >= 0.0f)
		return (hit1);
	else
		return (hit2);
}

t_hit	find_closest_collision(t_ray ray, t_obj_list *list)
{
	t_hit		closest_hit;
	t_hit		hitobj;
	t_hit		hitobj2;
	t_sphere	*sphere;
	t_triangle	*triangle;
	t_square	*square;
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
		if (list->type == SQ)
		{
			square = list->element;
			hitobj = intersect_ray_collision_square(ray, square);
			if (hitobj.d >= 0.0f)
			{
				if (hitobj.d < closest)
				{
					closest = hitobj.d;
					closest_hit = hitobj;
					closest_hit.obj = square->obj;
					closest_hit.uv = hitobj.uv;
				}
			}
		}
		list = list->next;
	}
	return (closest_hit);
}

