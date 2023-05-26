/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:03:37 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 22:26:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_bool	hit_sphere(t_sphere sp, t_ray ray, t_hit_record rec)
{
	t_vec3	cp;
	double	a;
	double	b;
	double	c;
	double	disc;
	double	root;

	cp = vsub(ray.origin, sp.center);
	a = vdot(ray.dir, ray.dir);
	b = 2.0 * vdot(cp, ray.dir);
	c = vdot(cp, cp) - (sp.radius * sp.radius);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (FALSE);
	// ...
}
