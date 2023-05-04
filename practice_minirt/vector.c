/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:50:12 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 17:54:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// d를 scalar로 바꾸자.

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	vset(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

// vlength2
//double	vec_len_pow(t_vec3 vec)
//{
//	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
//}
//
double	vlen(t_vec3 vec)
{
	double	ret;

	ret = pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0);
	return (sqrt(ret));
}

t_vec3	vadd_v(t_vec3 ret, t_vec3 vec)
{
	ret.x += vec.x;
	ret.y += vec.y;
	ret.z += vec.z;
	return (ret);
}

t_vec3	vadd_d(t_vec3 ret, double x, double y, double z)
{
	ret.x += x;
	ret.y += y;
	ret.z += z;
	return (ret);
}

t_vec3	vsub_v(t_vec3 ret, t_vec3 vec)
{
	ret.x -= vec.x;
	ret.y -= vec.y;
	ret.z -= vec.z;
	return (ret);
}

t_vec3	vsub_d(t_vec3 ret, double x, double y, double z)
{
	ret.x -= x;
	ret.y -= y;
	ret.z -= z;
	return (ret);
}

t_vec3	vmul_v(t_vec3 ret, t_vec3 vec)
{
	ret.x *= vec.x;
	ret.y *= vec.y;
	ret.z *= vec.z;
	return (ret);
}

t_vec3	vmul_d(t_vec3 ret, double t)
{
	ret.x *= t;
	ret.y *= t;
	ret.z *= t;
	return (ret);
}

t_vec3	vdiv_d(t_vec3 ret, double t)
{
	ret.x *= (1 / t);
	ret.y *= (1 / t);
	ret.z *= (1 / t);
	return (ret);
}

double	vdot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	vcross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.x = v1.y * v2.z + v1.z * v2.y;
	ret.y = v1.z * v2.x + v1.x * v2.z;
	ret.z = v1.x * v2.y + v1.y * v2.x;
	return (ret);
}

t_vec3	vunit(t_vec3 ret)
{
	double	len;

	len = vlen(ret);
	if (len == 0)
	{
		printf("Error: division by zero\n");
		exit(1);
	}
	ret.x /= len;
	ret.y /= len;
	ret.z /= len;
	return (ret);
}

t_vec3	vmin(t_vec3 ret, t_vec3 vec)
{
	if (ret.x > vec.x)
		ret.x = vec.x;
	if (ret.y > vec.y)
		ret.y = vec.y;
	if (ret.z > vec.z)
		ret.z = vec.z;
	return (ret);
}
