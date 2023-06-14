/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:29:10 by salee2            #+#    #+#             */
/*   Updated: 2023/05/31 17:29:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (sub(scl_mul(2 * dot(v, n), n), v));
}

t_color3	get_specular(t_scene *scene, t_vec3 light_dir, t_color3 color)
{
	const double	shininess_exp = 64;
	const double	reflection_coef = 0.5;
	const t_vec3	reflect_dir = reflect(light_dir, scene->hit.normal);
	const t_vec3	view_dir = norm(scl_mul(-1, scene->ray.dir));
	const double	intensity = pow(fmax(dot(view_dir, reflect_dir), 0.0), \
	shininess_exp);

	return (scl_mul(intensity, scl_mul(reflection_coef, color)));
}
