/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:31 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:32 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_bool	in_shadow(t_scene *scene, t_vec3 light_dir)
{
	const double	light_len = mag(light_dir);
	const t_color3	hit_point = add(scene->hit.point, \
	scl_mul(EPSILON, scene->hit.normal));
	t_hit			hit;
	t_ray			light_ray;

	light_ray = ray_(hit_point, light_dir);
	hit = hit_(light_len);
	if (hit_objects(scene->objects, &light_ray, &hit))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	const double	brightness = light->bright_ratio * LUMEN;
	const t_color3	ambient = scene->ambient;
	t_vec3			light_dir;
	t_color3		diffuse;
	t_color3		specular;

	light_dir = sub(light->origin, scene->hit.point);
	if (in_shadow(scene, light_dir))
		return (color3_(0, 0, 0));
	light_dir = norm(light_dir);
	diffuse = get_diffuse(scene->hit.normal, light_dir, light->color);
	specular = get_specular(scene, light_dir, light->color);
	return (scl_mul(brightness, add(add(ambient, diffuse), specular)));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_object		*lights;
	t_color3		light_color;

	light_color = color3_(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
		{
			light_color = add(light_color, \
			point_light_get(scene, lights->element));
		}
		lights = lights->next;
	}
	light_color = add(light_color, scene->ambient);
	light_color = hadam_prod(light_color, scene->hit.albedo);
	light_color = elem_min(light_color, color3_(1, 1, 1));
	return (light_color);
}
