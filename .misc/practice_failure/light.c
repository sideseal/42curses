/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:06:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 20:57:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
//	while (lights)
//	{
//		if (light->type == LIGHT_POINT)
//			light_color = vadd(light_color, point_light_get(scene, lights->element));
//		lights = lights->next;
//	}
	light_color = vadd(light_color, scene->ambient);
	return (vsub(vmult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
