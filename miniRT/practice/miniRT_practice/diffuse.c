/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:29:01 by salee2            #+#    #+#             */
/*   Updated: 2023/05/31 17:29:04 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_color3	get_diffuse(t_vec3 normal, t_vec3 light_dir, t_color3 color)
{
	double		diffuse_reflection_coef;
	t_color3	diffuse;

	diffuse_reflection_coef = fmax(dot(normal, light_dir), 0.0);
	diffuse = scl_mul(diffuse_reflection_coef, color);
	return (diffuse);
}
