/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:49:01 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/15 17:30:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	vlen(t_vec3 vec)
{
	double	ret;

	ret = pow(vec.x, 2.0f) + pow(vec.y, 2.0f) + pow(vec.z, 2.0f);
	return (sqrt(ret));
}

double	vlen_pow(t_vec3 vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
