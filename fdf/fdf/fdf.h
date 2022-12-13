/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/13 21:02:27 by gychoi           ###   ########.fr       */
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

typedef struct	s_ctx
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
}	t_ctx;

typedef struct	s_fdf
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_fdf;

void	fdf_error(void);

t_ctx	*init_ctx(char *path, int img_width, int img_height);
t_fdf	*init_fdf(t_ctx *ctx, int img_width, int img_height);

char	**read_from_file(t_ctx *ctx, char *path);
int	get_height(char **map);
int	get_width(char *line);

#endif
