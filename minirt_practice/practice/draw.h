/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:23:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 19:25:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libvec.h"
# include "mlx.h"
# include "struct.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, t_color3 pixel);

#endif
