/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:07:07 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 20:57:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "libvec.h"
# include "scene.h"

# define LIGHT_POINT 1

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

t_color3	phong_lighting(t_scene *scene);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif
