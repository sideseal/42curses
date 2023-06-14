/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:28 by salee2            #+#    #+#             */
/*   Updated: 2023/06/02 16:40:31 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_vec3	add(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.ai + v.ai, u.bj + v.bj, u.ck + v.ck));
}

t_vec3	sub(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.ai - v.ai, u.bj - v.bj, u.ck - v.ck));
}

t_vec3	elem_min(t_vec3 u, t_vec3 v)
{
	if (v.ai < u.ai)
		u.ai = v.ai;
	if (v.bj < u.bj)
		u.bj = v.bj;
	if (v.ck < u.ck)
		u.ck = v.ck;
	return (u);
}
