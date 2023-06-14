/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:10:34 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/07 21:34:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// canvas가 왜 필요할까?
t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	camera(t_canvas canvas, t_point3 origin)
{
	t_camera	cam;
	double		focal_len;
	double		vp_height;

	vp_height = 2.0;
	focal_len = 1.0;
	cam.origin = origin;
	cam.vp_height = vp_height;
	cam.vp_width = vp_height * canvas.aspect_ratio;
	cam.focal_len = focal_len;
	// changed
	cam.horizontal = vec3(cam.vp_width, 0, 0);
	cam.vertical = vec3(0, cam.vp_height, 0);
	cam.left_bottom = \
		vsub_v( \
			vsub_v( \
				vsub_v( \
					cam.origin, vdiv_d(cam.horizontal, 2)), \
				vdiv_d(cam.vertical, 2)), \
			vec3(0, 0, focal_len));
	return (cam);
}
