/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:27:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 20:50:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	set_data_value(char *elem, void *value, int type)
{
	int		error;

	error = FALSE;
	if (type == FLOAT)
		*(double *)value = rt_atof(elem, &error);
	if (type == INT)
		*(int *)value = ft_atoi(elem);
	if (error == TRUE)
		return (FALSE);
	return (TRUE);
}

t_bool	set_data_csv(char *elem, void *csv, int type_s, int type_d)
{
	int		err;
	char	**tokens;

	err = FALSE;
	tokens = ft_split(elem, ',');
	if ((type_s == COLOR) && (type_d == FLOAT))
		*(t_color3 *)csv = color3_(rt_atof(tokens[0], &err) / 255, \
			rt_atof(tokens[1], &err) / 255, rt_atof(tokens[2], &err) / 255);
	if ((type_s == COLOR) && (type_d == INT))
		*(t_color3 *)csv = color3_(ft_atoi(tokens[0]) / 255, \
			ft_atoi(tokens[1]) / 255, ft_atoi(tokens[2]) / 255);
	if ((type_s == POINT) && (type_d == FLOAT))
		*(t_point3 *)csv = point3_(rt_atof(tokens[0], &err), \
			rt_atof(tokens[1], &err), rt_atof(tokens[2], &err));
	if ((type_s == POINT) && (type_d == INT))
		*(t_point3 *)csv = point3_(ft_atoi(tokens[0]), \
			ft_atoi(tokens[1]), ft_atoi(tokens[2]));
	if ((type_s == VEC) && (type_d == FLOAT))
		*(t_vec3 *)csv = vec3_(rt_atof(tokens[0], &err), \
			rt_atof(tokens[1], &err), rt_atof(tokens[2], &err));
	if ((type_s == VEC) && (type_d == INT))
		*(t_vec3 *)csv = vec3_(ft_atoi(tokens[0]), \
			ft_atoi(tokens[1]), ft_atoi(tokens[2]));
	free_tokens(tokens);
	return (!err);
}
