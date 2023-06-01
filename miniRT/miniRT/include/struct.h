/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:02:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 23:13:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "typedef.h"

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_scene
{
};

struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_scene		*scene;
};

#endif
