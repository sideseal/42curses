/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:07:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/13 21:35:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_color3	color;
	t_vec3		amb;
	t_vec3		diff;
	t_vec3		spec;
	double		alpha;
	double		ks;
}	t_sphere;

t_sphere	*sphere(t_point3 center, double radius, t_color3 color);

#endif
