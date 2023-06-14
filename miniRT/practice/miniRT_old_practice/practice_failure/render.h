/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:17:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/28 21:08:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "camera.h"
#include "draw.h"
#include "hit.h"
#include "init.h"
#include "libvec.h"
#include "mlx.h"
#include "object.h"
#include "object_utils.h"
#include "pracrt.h"
#include "ray.h"

typedef struct s_scene
{
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

void	render(t_mlx mlx, t_img img);

#endif
