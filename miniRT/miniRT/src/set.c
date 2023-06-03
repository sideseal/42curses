/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:59 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/03 23:24:06 by gychoi           ###   ########.fr       */
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
	size_t	count;

	count = count_tokens(tokens);
	if (count != 3)
		print_read_error("mismatched element counts", data, tokens);
	if (check_elem_fmt(tokens) == FALSE)
		print_read_error("wrong element values", data, tokens);
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
	size_t	count;

	count = count_tokens(tokens);
	if (count < 1)
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
	else
		print_read_error("mismateched type", data, tokens);
}
