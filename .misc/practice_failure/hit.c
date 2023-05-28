/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:03:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 20:16:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *world, t_ray ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world->element, world->albedo, ray, rec);
	return (hit_result);
}

void	set_face_normal(t_ray r, t_hit_record *rec)
{
	rec->front_face = vdot(r.dir, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vmults(rec->normal, -1);
}

t_bool	hit_sphere(t_sphere *sp, t_color3 albedo, t_ray ray, t_hit_record *rec)
{
	t_vec3	cp;
	double	a;
	double	half_b;
	double	c;
	double	disc;
	double	sqrtd;
	double	root;

	cp = vsub(ray.origin, sp->center);
	a = vlen_pow(ray.dir);
	half_b = vdot(cp, ray.dir);
	c = vlen_pow(cp) - (sp->radius * sp->radius);
	disc = half_b * half_b - a * c;
	if (disc < 0)
		return (FALSE);
	sqrtd = sqrt(disc);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivs(vsub(rec->p, sp->center), sp->radius);
	rec->albedo = albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}
