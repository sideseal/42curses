/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:03:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/27 22:00:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "libvec.h"
# include "object.h"
# include "pracrt.h"
# include "ray.h"

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
}	t_hit_record;

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec);
t_bool	hit_obj(t_object *world, t_ray ray, t_hit_record *rec);
t_bool	hit_sphere(t_sphere *sp, t_ray ray, t_hit_record *rec);

#endif
