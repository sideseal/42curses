/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 21:10:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient(char **tokens, t_data *data)
{
	t_ambient	*ambient;

	ambient = &data->scene.ambient;
	if (ambient->lighting_ratio != INITIAL_VALUE)
		print_read_error("duplicated ambient element", NULL, data, tokens);
	if (check_element_count(tokens, 3) == FALSE)
		print_read_error("wrong ambient element count", NULL, data, tokens);
	if (check_element_value(tokens[1], LIGHT, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (set_data_value(tokens[1], &ambient->lighting_ratio, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &ambient->color, COLOR, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
}

void	set_camera(char **tokens, t_data *data)
{
	t_camera	*camera;

	camera = &data->scene.camera;
	if (camera->h_fov != INITIAL_VALUE)
		print_read_error("duplicated camera element", NULL, data, tokens);
	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong camera element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], NORM, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (check_element_value(tokens[3], FOV, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[1], &camera->look_from, POINT, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_csv(tokens[2], &camera->look_at, VEC, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	if (set_data_value(tokens[3], &camera->h_fov, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
}

void	set_light(char **tokens, t_data *data)
{
	t_light	*light;

	light = (t_light *)data->scene.lights->element;
	if (light->bright_ratio != INITIAL_VALUE)
		print_read_error("duplicated light element", NULL, data, tokens);
	if (check_element_count(tokens, 4) == FALSE)
		print_read_error("wrong light element count", NULL, data, tokens);
	if (check_element_csv(tokens[1], COORD, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_value(tokens[2], LIGHT, FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[1], &light->origin, POINT, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_value(tokens[2], &light->bright_ratio, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
}

void	set_data(char **tokens, t_data *data)
{
	if (count_tokens(tokens) < 1 || ft_strncmp(tokens[0], "#", 1) == 0)
		return ;
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		set_ambient(tokens, data);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		set_camera(tokens, data);
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
