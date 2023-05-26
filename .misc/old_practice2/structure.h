/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:44:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 17:37:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

#endif
