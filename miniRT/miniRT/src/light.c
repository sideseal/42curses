/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:51:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 19:55:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*light_(t_point3 orig, t_color3 color, double bright, t_data *data)
{
	t_light	*light;

	light = rt_malloc(sizeof(t_light), data);
	light->origin = orig;
	light->color = color;
	light->bright_ratio = bright;
	return (light);
}
