/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:30 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 22:08:19 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*cylinder_(t_point3 center, t_vec3 normal, t_vec2 dh, t_data *dat)
{
	t_cylinder	*cylinder;

	cylinder = rt_malloc(sizeof(t_cylinder), dat);
	cylinder->height = dh.y;
	cylinder->radius = dh.x;
	cylinder->radius_sq = dh.x * dh.x;
	cylinder->normal = norm(normal);
	cylinder->base_center = center;
	cylinder->top_center = add(cylinder->base_center, \
		scl_mul(cylinder->height, cylinder->normal));
	return (cylinder);
}
