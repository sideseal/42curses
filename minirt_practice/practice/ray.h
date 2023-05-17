/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 21:55:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "object.h"
# include "light.h"
# include "list.h"

typedef struct s_ray
{
	t_point3	start;
	t_vec3		dir;
}	t_ray;

t_ray		ray(t_point3 start, t_vec3 dir);
t_color3	trace_ray(t_ray ray, t_obj_list *list, t_light light, int recursive_level);
t_color3	trace_ray_2x2(t_vec3 eye_pos, t_color3 pixel_pos, double dx, int recursive_level, t_obj_list *list, t_light light);

#endif
