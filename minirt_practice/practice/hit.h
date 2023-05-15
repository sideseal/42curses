/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:12:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/15 23:34:28 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "object.h"
# include "ray.h"
# include "list.h"

typedef struct s_hit
{
	double		d;
	t_point3	point;
	t_vec3		normal;
	t_object	obj;
	double		w0;
	double		w1;
}	t_hit;

t_hit	find_closest_collision(t_ray ray, t_obj_list *list);

#endif
