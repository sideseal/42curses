/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 17:45:34 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	set_canvas(int height)
{
	t_canvas	canvas;

	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.height = height;
	canvas.width = height * canvas.aspect_ratio;
	return (canvas);
}
