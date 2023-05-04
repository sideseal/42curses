/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:48:58 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 17:49:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

typedef struct s_camera
{
	t_point3	origin;
	double		vp_height;
	double		vp_width;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
}	t_sphere;

#endif
