/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:28:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 20:32:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	camera(t_point3 origin)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.origin = origin;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * ASPECT_RATIO;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = vsub(vsub(vsub(cam.origin, vdivs(cam.horizontal, 2.0)),\
					vdivs(cam.vertical, 2.0)), vec3(0, 0, focal_len));
	return (cam);
}
