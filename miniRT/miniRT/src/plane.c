/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 21:47:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*plane_(t_point3 point, t_vec3 normal, t_data *data)
{
	t_plane	*plane;

	plane = rt_malloc(sizeof(t_plane), data);
	plane->point = point;
	plane->normal = normal;
	return (plane);
}
