/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/04 21:11:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *fdf)
{
	fdf->angle.alpha = M_PI / 4 * -1;
	fdf->angle.beta = asin(tan(M_PI / 6));
	fdf->angle.gamma = 0;
}

void	orthographic(t_fdf *fdf)
{
	fdf->angle.alpha = 0;
	fdf->angle.beta = 0;
	fdf->angle.gamma = 0;
}

void	reset_translation(t_fdf *fdf)
{
	fdf->offset.x = 0;
	fdf->offset.y = 0;
	fdf->offset.z = 1.0;
	fdf->offset.zoom = 1.0;
	fdf->offset.bend = 0;
}
