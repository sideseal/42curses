/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:11:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 20:26:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element);
void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);

#endif
