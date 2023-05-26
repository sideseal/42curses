/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:04:03 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 20:07:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	return (sp);
}
