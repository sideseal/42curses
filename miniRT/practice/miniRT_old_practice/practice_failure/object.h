/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:04:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 20:13:36 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "libvec.h"

typedef int	t_object_type;
# define SP 0

typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}	t_sphere;

t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);

#endif
