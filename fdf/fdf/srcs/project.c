/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 21:52:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// https://gaussian37.github.io/math-la-rotation_matrix/
// y축으로 45도 돌리고, y축으로 30도 돌리면, 120도, 30도 차이가 난다. 여기서 z축으로 돌리는 이유는, 우리가 원하는 관점을 갖기 위해...
// https://ko.wikipedia.org/wiki/등축_투영법
//rotate_x(p, 3.14 / 45);
//rotate_y(p, 3.14 / (180 / 35));
//fdf->angle.alpha = -0.6981;
//fdf->angle.beta = 0.5774;
//fdf->angle.gamma = 0.5236;
// 좌표계 변환을 위해 z축에 -1을 곱하는가? -> 왼손에서 오른손으로!
void	isometric(t_fdf *fdf)
{
	fdf->angle.alpha = M_PI / 4 * -1;
	fdf->angle.beta = asin(tan(M_PI / 6));
	fdf->angle.gamma = 0;
}

void	orthographic(t_fdf *fdf)
{
	fdf->angle.alpha = M_PI / 2 * -1;
	fdf->angle.beta = 0;
	fdf->angle.gamma = 0;
}

void	reset_translation(t_fdf *fdf)
{
	fdf->offset.x = 0;
	fdf->offset.y = 0;
	fdf->offset.z = 1.0;
	fdf->offset.zoom = 1.0;
}
