/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:03:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/26 22:01:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

void	set_face_normal(t_ray r, t_hit_record *rec)
{
	rec->front_face = 

t_bool	hit_sphere(t_sphere sp, t_ray ray, t_hit_record *rec)
{
	t_vec3	cp;
	double	a;
	double	half_b;
	double	c;
	double	disc;
	double	sqrtd;
	double	root;

	cp = vsub(ray.origin, sp.center);
	a = vlen_pow(ray.dir);
	half_b = vdot(cp, ray.dir);
	c = vlen_pow(cp) - (sp.radius * sp.radius);
	disc = b * b - a * c;
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
	rec->normal = vdivs(vsub(rec->p, sp.center), sp.radius);
	set_face_normal(ray, rec);
	return (TRUE);
}
