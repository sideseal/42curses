/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:53:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 18:07:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	hit_sphere(t_sphere sp, t_ray ray)
{
	t_vec3	oc;

	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vsub_v(ray.origin, sp.center);
	a = vdot(ray.direction, ray.direction);
	b = 2.0 * vdot(oc, ray.direction);
	c = vdot(oc, oc) - sp.radius2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
