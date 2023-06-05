/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:06 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 21:46:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*sphere_(t_point3 center, double radius, t_data *data)
{
	t_sphere	*sphere;

	sphere = rt_malloc(sizeof(t_sphere), data);
	sphere->center = center;
	sphere->radius = radius;
	sphere->radius_sq = radius * radius;
	return (sphere);
}
