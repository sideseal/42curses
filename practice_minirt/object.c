/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:50:01 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 18:01:07 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	sphere.radius2 = radius * radius;
	return (sphere);
}
