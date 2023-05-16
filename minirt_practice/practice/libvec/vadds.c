/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vadds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:50:44 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 16:42:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2adds(t_vec2 ret, double u, double v)
{
	ret.u += u;
	ret.v += v;
	return (ret);
}

t_vec3	vadds(t_vec3 ret, double x, double y, double z)
{
	ret.x += x;
	ret.y += y;
	ret.z += z;
	return (ret);
}
