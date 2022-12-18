/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/19 02:20:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct	s_map
{
	int	width;
	int	height;
	struct s_point	*point;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	struct s_point	*next;
}	t_point;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	struct s_map	*map;
}	t_fdf;

void	fdf_error(char *str);

#endif
