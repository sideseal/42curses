/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:11:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/07 21:27:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);
void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);

#endif
