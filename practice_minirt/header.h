/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:15:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/05 21:53:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// 불필요한 헤더 방지를 위해, 필요한 헤더를 모두 나눠야 하는데, 편의상 일단 한 헤더에 몰아넣었다.
# include "structure.h"
# include "vector.h"
# include "ray.h"
# include "scene.h"

# define SCREEN_WIDTH 500
# define SCREEN_HEIGHT 500
# define TRUE 1
# define FALSE 0

double	clamp(double x, double min, double max);
double	rand_num(int anti);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		trgb_anti(t_color3 *color, int anti, int t);
int		write_color(int t, t_color3 pixel_color);

int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);

#endif
