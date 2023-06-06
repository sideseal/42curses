/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:53:46 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 21:10:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (set_data_csv(tokens[1], &center, POINT, FLOAT) == FALSE)
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
	if (set_data_csv(tokens[5], &color, COLOR, FLOAT) == FALSE)
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
	if (set_data_csv(tokens[1], &point, POINT, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &normal, VEC, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	return (plane_(point, normal, data));
}

void	set_object_plane(char **tokens, t_data *data)
{
	t_plane		*plane;
	t_color3	color;

	plane = set_plane(tokens, data);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[3], &color, COLOR, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
	if (data->scene.objects == NULL)
		data->scene.objects = object_(PLANE, plane, color, data);
	else
		append(&data->scene.objects, object_(PLANE, plane, color, data));
}
