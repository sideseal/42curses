/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/22 23:15:29 by gychoi           ###   ########.fr       */
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
	int		color;
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
void	free_fdf(t_fdf *fdf);
void	read_and_set(t_fdf *fdf, char *path);

t_point	*fdf_lstnew(int x, int y, int z);
t_point	*fdf_lstlast(t_point *point);
void	fdf_lstadd_back(t_point **point, t_point *new);
void	fdf_lstclear(t_point **point);

t_map	*init_map(void);
t_fdf	*init_fdf(t_fdf *fdf, int win_width, int win_height);

#endif
