/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:52:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 20:33:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	_degree_to_radian(double degree)
{
	return (degree * M_PI / 180.0);
}

static double	_get_width(double h_fov)
{
	double	theta;
	double	width;

	theta = _degree_to_radian(h_fov);
	width = tan(theta / 2.0);
	return (width);
}

t_camera	camera_(t_canvas canvas, t_point3 from, t_vec3 at, double h_fov)
{
	t_camera	camera;
	t_vec3		jup;
	t_vec3		i;
	t_vec3		j;
	t_vec3		k;

	camera.h_fov = h_fov;
	camera.viewport_w = 2.0 * _get_width(camera.h_fov);
	camera.viewport_h = camera.viewport_w / canvas.aspect_ratio;
	camera.look_from = from;
	camera.look_at = at;
	jup = vec3_(0, 1, 0);
	k = norm(sub(camera.look_from, camera.look_at));
	i = norm(cross(jup, k));
	j = cross(k, i);
	camera.ai = scl_mul(camera.viewport_w, i);
	camera.bj = scl_mul(camera.viewport_h, j);
	camera.lower_left_corner = sub(sub(sub(camera.look_from, \
		scl_mul(0.5, camera.ai)), scl_mul(0.5, camera.bj)), k);
	return (camera);
}
