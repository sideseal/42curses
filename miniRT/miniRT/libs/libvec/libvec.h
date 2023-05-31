/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:33:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/31 20:43:37 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

typedef struct s_vec2	t_vec2;
typedef struct s_vec2	t_point2;

struct s_vec2
{
	double	x;
	double	y;
};

typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

#endif
