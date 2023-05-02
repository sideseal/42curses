/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:50:12 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/02 21:50:40 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}

t_vec	vec_mul(t_vec v1, double t)
{
	t_vec	ret;

	ret.x = v1.x * t;
	ret.y = v1.y * t;
	ret.z = v1.z * t;
	return (ret);
}

t_vec	vec_div(t_vec v1, double t)
{
	t_vec	ret;

	ret.x = v1.x * (1 / t);
	ret.y = v1.y * (1 / t);
	ret.z = v1.z * (1 / t);
	return (ret);
}

double	vec_len(t_vec v1)
{
	double	ret;

	ret = pow(v1.x, 2.0) + pow(v1.y, 2.0) + pow(v1.z, 2.0);
	return (sqrt(ret));
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.y * v2.z + v1.z * v2.y;
	ret.y = v1.z * v2.x + v1.x * v2.z;
	ret.z = v1.x * v2.y + v1.y * v2.x;
	return (ret);
}

t_vec	vec_unit(t_vec v1)
{
	double	len;
	double	ret_x;
	double	ret_y;
	double	ret_z;

	len = vec_len(v1);
	if (len == 0)
	{
		// error
		exit(1);
	}
	ret_x = v1.x / len;
	ret_y = v1.y / len;
	ret_z = v1.z / len;
	return (vec(ret_x, ret_y, ret_z));
}
