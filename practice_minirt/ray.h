/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:11:09 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 17:58:51 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef int	t_bool;

t_ray		ray(t_point3 origin, t_vec3 direction);
t_point3	ray_at(t_ray ray, double t);
t_ray		ray_primary(t_camera cam, double u, double v);
t_color3	ray_color(t_ray ray, t_sphere sphere);
t_bool		hit_sphere(t_sphere sp, t_ray ray);

#endif
