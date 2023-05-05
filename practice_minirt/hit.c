/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:53:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 21:10:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// need to fix
void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray.direction, rec->normal) < 0;
	if (rec->front_face >= 0)
		rec->normal = vmul_d(rec->normal, -1);
}

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_object(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_object(t_object *world, t_ray ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere((t_sphere *)world->element, ray, rec);
	return (hit_result);
}

t_bool	hit_sphere(t_sphere *sp, t_ray ray, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

	oc = vsub_v(ray.origin, sp->center);
	a = vlen_pow(ray.direction);
	b = vdot(oc, ray.direction);
	c = vlen_pow(oc) - sp->radius2;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdiv_d(vsub_v(rec->p, sp->center), sp->radius);
	//set_face_normal(ray, rec);
	rec->front_face = vdot(ray.direction, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmul_d(rec->normal, -1);
	return (TRUE);
}
