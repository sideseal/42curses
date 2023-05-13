/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/13 22:09:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "object.h"
# include "light.h"

typedef struct s_ray
{
	t_point3	start;
	t_vec3		dir;
}	t_ray;

t_ray		ray(t_point3 start, t_vec3 dir);
t_color3	trace_ray(t_ray ray, t_sphere *sphere, t_light light);

#endif
