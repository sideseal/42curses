/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:57 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:58 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPEDEF_H
#define MINIRT_TYPEDEF_H

typedef int t_bool;

typedef struct s_vector2
{
	double x, y;
}	t_vec2;

typedef struct s_vector3
{
	union {
		struct {double ai,bj,ck;};
		struct {double x,y,z;};
		struct {double r,g,b;};
		struct {double arr[3];};
	};
}	t_vec3;

typedef t_vec3 t_color3;
typedef t_vec3 t_point3;

typedef struct s_ray
{
	t_vec3		dir;
	t_point3	origin;
}	t_ray;

typedef struct s_plane
{
	t_vec3		normal;
	t_point3	point;
}	t_plane;

typedef struct s_sphere
{
	double		radius;
	double		radius_sq;
	t_point3	center;
}	t_sphere;

typedef struct s_cylinder
{
	double		height;
	double		radius;
	double		radius_sq;
	t_vec3		normal;
	t_point3	top_center;
	t_point3	base_center;
}	t_cylinder;

typedef struct s_cone
{
	double		height;
	double		radius;
	double		radius_sq;
	t_vec3		normal;
	t_vec3		h_dir;
	t_vec3		h_normal;
	t_point3	tip_center;
	t_point3	base_center;
}	t_cone;

typedef struct s_raytracer
{
	int width;
	int height;
	t_sphere sphere;
}	t_raytracer;

typedef struct s_hit
{
	double		t;
	double		t_min;
	double		t_max;
	t_vec3		normal;
	t_point3	point;
	t_color3	albedo;
}	t_hit;

typedef struct s_camera
{
	double		viewport_w;
	double		viewport_h;
	t_point3	origin;
	t_point3	lower_left_corner;
	t_vec3		ai;
	t_vec3		bj;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef int t_object_type;

typedef struct s_object
{
	void			*element;
	void			*next;
	t_color3		albedo;
	t_object_type	type;
}	t_object;

typedef struct s_light
{
	t_point3 origin;
	t_color3 color;
	double bright_ratio;
}	t_light;

typedef struct s_scene
{
	t_ray		ray;
	t_hit		hit;
	t_canvas	canvas;
	t_camera	camera;
	t_color3	ambient;
	t_object	*light;
	t_object	*objects;
}	t_scene;

typedef struct s_coefficient
{
	double a;
	double b;
	double c;
}	t_coefficient;

typedef struct	mlx_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;


typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_mlx_data	img;
	t_scene		*scene;
}	t_vars;

#endif //MINIRT_TYPEDEF_H
