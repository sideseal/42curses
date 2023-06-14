/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:20:48 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:20:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180.0);
}

double	get_width(double h_fov)
{
	const double	theta = degree_to_radian(h_fov);
	const double	width = tan(theta / 2);

	return (width);
}

t_camera	camera_(t_canvas *canvas, t_point3 look_from, t_point3 look_at, \
double h_fov)
{
	t_camera		this;
	const t_vec3	jup = vec3_(0, 1, 0);
	const t_vec3	k = norm(sub(look_from, look_at));
	const t_vec3	i = norm(cross(jup, k));
	const t_vec3	j = cross(k, i);

	this.viewport_w = 2.0 * get_width(h_fov);
	this.viewport_h = this.viewport_w / canvas->aspect_ratio;
	this.origin = look_from;
	this.ai = scl_mul(this.viewport_w, i);
	this.bj = scl_mul(this.viewport_h, j);
	this.lower_left_corner = sub(sub(sub(this.origin, \
	scl_mul(1.0 / 2.0, this.ai)), scl_mul(1.0 / 2.0, this.bj)), k);
	return (this);
}
