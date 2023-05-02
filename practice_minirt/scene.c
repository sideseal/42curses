/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:12:20 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/02 21:26:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	camera(t_canvas canvas, t_point orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas.aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec(cam.viewport_w, 0, 0);
	cam.vertical = vec(0, cam.viewport_h, 0);
	cam.left_bottom = cam.orig - cam.horizontal / 2 - cam.vertical / 2 - vec(0, 0, cam.focal_len);
	cam.left_bottom = (t_point)vec_sub(vec_sub(vec_sub((t_vec)cam.orig, vec_div(cam.horizontal, 2)), vec_div(cam.vertical, 2)), vec(0, 0, cam.focal_len));
	return (cam);
}
