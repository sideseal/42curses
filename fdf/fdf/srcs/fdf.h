/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 01:33:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	960

# define KEY_ESC		53
# define KEY_ISO		34
# define KEY_W			13
# define KEY_S			1
# define KEY_A			0
# define KEY_D			2
# define KEY_Q			12
# define KEY_E			14
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ZOOM_IN	24
# define KEY_ZOOM_OUT	27
# define KEY_Z_UP		30
# define KEY_Z_DOWN		33

# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x00FF00
# define COLOR_BLUE		0x0000FF
# define COLOR_BLACK	0x000000
# define COLOR_WHITE	0xFFFFFF

typedef struct s_delta
{
	int	dx;
	int	dy;
}	t_delta;

typedef struct	s_map
{
	int	width;
	int	height;
	int	x_origin;
	int	y_origin;
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
	int		color;
}	t_point;

typedef struct	s_angle
{
	double	alpha;
	double	beta;
	double	gamma;
}	t_angle;

typedef struct	s_offset
{
	int	x;
	int	y;
	double	z;
	double	zoom;
}	t_offset;

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
	struct s_angle	angle;
	struct s_offset	offset;
}	t_fdf;

void	read_and_set(t_fdf *fdf, char *path);

t_fdf	*init_fdf(void);
void	init_draw(t_fdf *fdf);
t_coord	init_coord(int x, int y, int z);

t_point	**set_points(t_fdf *fdf, int keycode);

void	rotate_x(t_point *point, double theta);
void	rotate_y(t_point *point, double theta);
void	rotate_z(t_point *point, double theta);
void	isometric(t_coord coord, t_point *p, t_fdf *fdf);

void	draw_frame(t_fdf *fdf, int keycode);

int		key_hook(int keycode, t_fdf *fdf);
int		close_hook(t_fdf *fdf);

void	fdf_error(char *str);
int	fdf_abs(int n);
int	fdf_open(char *path, int flag);
void	fdf_close(int fd);
void	*fdf_malloc(size_t size);

#endif
