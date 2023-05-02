/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:45:19 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/02 21:56:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray	ray(t_vec orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_vec	ray_at(t_ray ray, double t)
{
	t_vec	dist;
	t_vec	tmp;

	tmp.x = ray.orig.x;
	tmp.y = ray.orig.y;
	tmp.z = ray.orig.z;
	dist = vec_add(tmp, vec_mul(ray.dir, t));
	return (dist);
}
