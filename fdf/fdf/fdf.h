/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:08 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/10 22:46:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_var
{
	void	*mlx;
	void	*win;
}	t_var;

typedef struct	s_fdf
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_fdf;

#endif
