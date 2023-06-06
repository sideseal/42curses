/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:54:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 21:11:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (set_data_csv(tokens[1], &center, POINT, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	if (set_data_value(tokens[2], &radius, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[2], data, tokens);
	return (sphere_(center, radius, data));
}

void	set_object_sphere(char **tokens, t_data *data)
{
	t_sphere	*sphere;
	t_color3	color;

	sphere = set_sphere(tokens, data);
	if (check_element_csv(tokens[3], RGB, INT) == FALSE)
		print_read_error("wrong element values", tokens[3], data, tokens);
	if (set_data_csv(tokens[3], &color, COLOR, FLOAT) == FALSE)
		print_read_error("cannot set element values", tokens[3], data, tokens);
	if (data->scene.objects == NULL)
		data->scene.objects = object_(SPHERE, sphere, color, data);
	else
		append(&data->scene.objects, object_(SPHERE, sphere, color, data));
}
