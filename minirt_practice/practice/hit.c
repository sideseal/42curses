/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/13 21:13:19 by gychoi           ###   ########.fr       */
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

t_hit	intersect_ray_collision(t_ray ray, t_sphere *sphere)
{
	t_hit	hitobj;
	double	b;
	double	c;
	double	nabla;
	double	d1;
	double	d2;

	hitobj = hit(-1.0, point3(0, 0, 0), vec3(0, 0, 0));
	b = 2.0 * vdot(ray.dir, vsub(ray.start, sphere->center));
	c = vdot(vsub(ray.start, sphere->center), vsub(ray.start, sphere->center)) - sphere->radius * sphere->radius;
	nabla = b * b / 4.0 - c;

	if (nabla >= 0.0)
	{
		d1 = -b / 2.0 + sqrt(nabla);
		d2 = -b / 2.0 - sqrt(nabla);
		hitobj.d = d2;
		if (d1 < d2)
			hitobj.d = d1;
		hitobj.point = vmults(vadd(ray.start, ray.dir), hitobj.d);
		hitobj.normal = vunit(vsub(hitobj.point, sphere->center));
	}
	return (hitobj);
}
