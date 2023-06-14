/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:34:40 by salee2            #+#    #+#             */
/*   Updated: 2023/06/02 16:34:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_vec3	scl_mul(double t, t_vec3 vector)
{
	return (vec3_(t * vector.ai, t * vector.bj, t * vector.ck));
}

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.ai * v.ai + u.bj * v.bj + u.ck * v.ck);
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.bj * v.ck - u.ck * v.bj, u.ck * v.ai - u.ai * v.ck, \
	u.ai * v.bj - u.bj * v.ai));
}

t_vec3	elem_prod(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.ai * v.ai, u.bj * v.bj, u.ck * v.ck));
}
