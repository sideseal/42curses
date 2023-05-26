/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:04:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 20:19:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "libvec.h"

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
}	t_sphere;

t_sphere	sphere(t_point3 center, double radius);

#endif
