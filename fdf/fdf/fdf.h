/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/24 22:26:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	960

# define KEY_ESC		53

# define COLOR_RED	0xFF0000
# define COLOR_GREEN	0x00FF00
# define COLOR_BLUE	0x0000FF
# define COLOR_BLACK	0x000000
# define COLOR_WHITE	0xFFFFFF

typedef	struct	s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_point;

typedef struct	s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	struct s_map	map;
	struct s_coord	**coords;
}	t_fdf;

void	read_and_set(t_fdf *fdf, char *path);

t_map	init_map(void);
t_coord	init_coord(int x, int y, int z);
t_fdf	*init_fdf(t_fdf *fdf);

t_point	set_point(t_coord coord, t_map map);

void	draw_frame(t_fdf *fdf);

int	key_hook(int keycode, t_fdf *fdf);
int	close_hook(t_fdf *fdf);

void	fdf_error(char *str);

#endif
