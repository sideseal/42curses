/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:48:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 20:22:28 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "camera.h"
# include "libvec.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
}	t_ray;

t_ray		ray_primary(t_camera cam, double u, double v);
t_color3	ray_color(t_ray r, t_sphere sp);
t_point3	ray_at(t_ray ray, double t);
t_ray		ray(t_point3 origin, t_vec3 dir);

#endif
