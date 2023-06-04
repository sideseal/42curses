/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 23:09:08 by gychoi           ###   ########.fr       */
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
	int	error;

	error = FALSE;
	if (check_element_count(tokens) == FALSE)
		print_read_error("mismatched element counts", NULL, data, tokens);
	if (check_element_value(tokens[1], FLOAT) == FALSE)
		print_read_error("wrong element values", tokens[1], data, tokens);
	if (check_element_csv(tokens[2], INT) == FALSE)
		print_read_error("wrong element values", tokens[2], data, tokens);
	data->scene.ambient.lighting_ratio = rt_atof(tokens[1], &error);
	if (error == TRUE)
		print_read_error("cannot set element values", tokens[1], data, tokens);
	// make set_csv 글로벌하게...
}

void	set_camera(char **tokens, t_data *data)
{
	printf("%s: Camera", tokens[0]);
	if (printf("\n") < 1)
		print_error("whatever", data);
}

void	set_light(char **tokens, t_data *data)
{
	printf("%s: Light", tokens[0]);
	if (printf("\n") < 1)
		print_error("whatever", data);
}

void	set_object(char **tokens, t_data *data)
{
	printf("%s: Objects", tokens[0]);
	if (printf("\n") < 1)
		print_error("whatever", data);
}

// ambient
// camera
// light
// objects
void	set_data(char **tokens, t_data *data)
{
	if (count_tokens(tokens) < 1)
		return ;
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		set_ambient(tokens, data);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		set_camera(tokens, data);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		set_light(tokens, data);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0 \
			|| ft_strncmp(tokens[0], "pl", 3) == 0 \
			|| ft_strncmp(tokens[0], "cy", 3) == 0)
		set_object(tokens, data);
	else if (ft_strncmp(tokens[0], "#", 1) == 0)
		return ;
	else
		print_read_error("mismateched type", tokens[0], data, tokens);
}
