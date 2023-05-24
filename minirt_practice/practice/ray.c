/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:48:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 21:32:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	ray_at;

	ray_at = vadd(ray.origin, vmults(ray.dir, t));
	return (ray_at);
}

t_ray	ray(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir; // vunit?
	return (ray);
}
