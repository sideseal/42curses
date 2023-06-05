/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 23:12:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	set_canvas(int height)
{
	t_canvas	canvas;

	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.height = height;
	canvas.width = height * canvas.aspect_ratio;
	return (canvas);
}

void	set_ambient(char **tokens, t_data *data)
{
	t_ambient	*ambient;

	ambient = &data->scene.ambient;
	if (check_element_count(tokens, 3) == FALSE)
		print_read_error("wrong ambient element count", NULL, data, tokens);
	if (check_element_value(tokens[1], LIGHT, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (set_data_value(tokens[1], &ambient->lighting_ratio, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &ambient->color, COLOR, INT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
}

void	set_camera(char **tokens, t_data *data)
{
	printf("%s: Camera", tokens[0]);
	if (printf("\n") < 1)
		print_error("whatever", data);
}

void	set_light(char **tokens, t_data *data)
{
	t_light	*light;

	light = init_light(data);
	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong light element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_value(tokens[2], LIGHT, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[1], &light->origin, COORD, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_value(tokens[2], &light->bright_ratio, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	if (data->scene.lights == NULL)
		data->scene.lights = object_(LIGHT_POINT, light, light->color, data);
}

t_cylinder	*set_cylinder(char **tokens, t_data *data)
{
	t_vec2		dh;
	t_point3	center;
	t_vec3		normal;

	if (check_element_count(tokens, 6) == FALSE)
		print_read_error("wrong cylinder element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], NORM, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (check_element_value(tokens[3], DIMEN, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (check_element_value(tokens[4], DIMEN, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[4], data, tokens);
	if (set_data_csv(tokens[1], &center, COORD, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &normal, VEC, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	if (set_data_value(tokens[3], &dh.x, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
	if (set_data_value(tokens[4], &dh.y, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[4], data, tokens);
	return (cylinder_(center, normal, dh, data));
}

void	set_object_cylinder(char **tokens, t_data *data)
{
	t_cylinder	*cylinder;
	t_color3	color;

	cylinder = set_cylinder(tokens, data);
	if (check_element_csv(tokens[5], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[5], data, tokens);
	if (set_data_csv(tokens[5], &color, COLOR, INT) == FALSE)
		print_read_error("cannot set element values", tokens[5], data, tokens);
	if (data->scene.objects == NULL)
		data->scene.objects = object_(CYLINDER, cylinder, color, data);
	else
		append(&data->scene.objects, object_(CYLINDER, cylinder, color, data));
}

t_plane	*set_plane(char **tokens, t_data *data)
{
	t_point3	point;
	t_vec3		normal;

	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong plane element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], NORM, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (set_data_csv(tokens[1], &point, COORD, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &normal, VEC, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	return (plane_(point, normal, data));
}

t_sphere	*set_sphere(char **tokens, t_data *data)
{
	t_point3	center;
	double		radius;

	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong sphere element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_value(tokens[2], DIMEN, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (set_data_csv(tokens[1], &center, COORD, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_value(tokens[2], &radius, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	return (sphere_(center, radius, data));
}

void	set_object_plane(char **tokens, t_data *data)
{
	t_plane		*plane;
	t_color3	color;

	plane = set_plane(tokens, data);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[3], &color, COLOR, INT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
	if (data->scene.objects == NULL)
		data->scene.objects = object_(PLANE, plane, color, data);
	else
		append(&data->scene.objects, object_(PLANE, plane, color, data));
}

void	set_object_sphere(char **tokens, t_data *data)
{
	t_sphere	*sphere;
	t_color3	color;

	sphere = set_sphere(tokens, data);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[3], &color, COLOR, INT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
	if (data->scene.objects == NULL)
		data->scene.objects = object_(SPHERE, sphere, color, data);
	else
		append(&data->scene.objects, object_(SPHERE, sphere, color, data));
}

// 중복 체크하기
// ambient - OK
// camera
// light - OK
// objects
void	set_data(char **tokens, t_data *data)
{
	if (count_tokens(tokens) < 1 || ft_strncmp(tokens[0], "#", 1) == 0)
		return ;
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		set_ambient(tokens, data);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		//set_camera(tokens, data);
		;
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		set_light(tokens, data);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		set_object_cylinder(tokens, data);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		set_object_plane(tokens, data);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		set_object_sphere(tokens, data);
	else
		print_read_error("mismateched type", tokens[0], data, tokens);
}
