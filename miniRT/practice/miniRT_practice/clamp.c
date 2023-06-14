/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:07 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:09 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

double clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

t_vec3 clamp_vec3(t_vec3 value, t_vec3 min, t_vec3 max)
{
	int 		i;
	const int	size = 3;
	t_vec3		clamped_vec3;

	i = 0;
	while (i < size)
	{
		clamped_vec3.arr[i] = clamp(value.arr[i], min.arr[i], max.arr[i]);
		++i;
	}
	return (clamped_vec3);
}
