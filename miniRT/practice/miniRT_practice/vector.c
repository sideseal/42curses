/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:08 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:09 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_vec2 vec2_(double x, double y)
{
	t_vec2 this;

	this.x = x;
	this.y = y;
	return (this);
}

t_vec3 vec3_(double ai, double bj, double ck)
{
	t_vec3 this;

	this.ai = ai;
	this.bj = bj;
	this.ck = ck;
	return (this);
}

t_point3 point3_(double x, double y, double z)
{
	t_point3 this;

	this.x = x;
	this.y = y;
	this.z = z;
	return this;
}

t_color3 color3_(double r, double g, double b)
{
	t_color3 this;

	this.r = r;
	this.g = g;
	this.b = b;
	return this;
}

t_vec3	add(t_vec3 u,  t_vec3 v)
{
	return (t_vec3){{{u.ai + v.ai, u.bj + v.bj, u.ck + v.ck}}};
}

t_vec3	sub(t_vec3 u,  t_vec3 v)
{
	return (t_vec3){{{u.ai - v.ai, u.bj - v.bj, u.ck - v.ck}}};
}

t_vec3 scl_mul(double t, t_vec3 vector)
{
	return (t_vec3){{{t * vector.ai, t * vector.bj, t * vector.ck}}};
}

double mag_sq(t_vec3 vec)
{
	return (vec.ai * vec.ai + vec.bj * vec.bj + vec.ck * vec.ck);
}

double mag(t_vec3 vec)
{
	return (sqrt(mag_sq(vec)));
}

t_vec3 norm(t_vec3 vector)
{
	double m = mag(vector);

//	if (m == 0)
//	{
//		printf("Error\n:Devider is 0");
//		exit(EXIT_FAILURE);
//	}
	return (scl_mul(1.0/m, vector));
}

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.ai * v.ai + u.bj * v.bj + u.ck * v.ck);
}

t_vec3 cross(t_vec3 u, t_vec3 v)
{
	return ((t_vec3) {{{u.bj * v.ck - u.ck * v.bj,
						u.ck * v.ai - u.ai * v.ck,
						u.ai * v.bj - u.bj * v.ai}}});
}

t_vec3	hadam_prod(t_vec3 u, t_vec3 v)
{
	return (t_vec3) {{{u.ai * v.ai, u.bj * v.bj, u.ck * v.ck}}};
}

t_vec3	elem_min(t_vec3 u,  t_vec3 v)
{
	if(v.ai < u.ai)
		u.ai = v.ai;
	if(v.bj < u.bj)
		u.bj = v.bj;
	if(v.ck < u.ck)
		u.ck = v.ck;
	return (u);
}
