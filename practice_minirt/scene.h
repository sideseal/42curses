/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:11:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 17:51:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas canvas, t_point3 origin);
t_sphere	sphere(t_point3 center, double radius);

#endif
