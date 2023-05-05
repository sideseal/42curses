/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:11:09 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 21:10:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

t_ray		ray(t_point3 origin, t_vec3 direction);
t_point3	ray_at(t_ray ray, double t);
t_ray		ray_primary(t_camera cam, double u, double v);
t_color3	ray_color(t_ray ray, t_object *world);
t_bool		hit(t_object *world, t_ray ray, t_hit_record *rec);
t_bool		hit_object(t_object *world, t_ray ray, t_hit_record *rec);
t_bool		hit_sphere(t_sphere *sp, t_ray ray, t_hit_record *rec);
void		set_face_normal(t_ray ray, t_hit_record *rec);

#endif
