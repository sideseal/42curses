/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:55 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/25 00:05:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 벡터로 변환할 것.
static void	isometric(t_point *p)
{
	double	prev_x;
	double	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(0.5236);
	p->y = (prev_x + prev_y) * sin(0.5236) - p->z;
}

// 화면 중간에 어떻게 오도록 하지...
t_point	set_point(t_coord coord, t_map map)
{
	t_point	new;

	new.x = coord.x * (SCREEN_WIDTH / map.width / 2);
	new.y = coord.y * (SCREEN_HEIGHT / map.height / 2);
	new.z = coord.z;
	isometric(&new);
	new.x += SCREEN_WIDTH / 2;
	new.y += SCREEN_HEIGHT / 2 / 2;
	return (new);
}
