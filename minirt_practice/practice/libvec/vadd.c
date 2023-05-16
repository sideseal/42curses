/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vadd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:50:07 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 16:40:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2add(t_vec2 ret, t_vec2 vec)
{
	ret.u += vec.u;
	ret.v += vec.v;
	return (ret);
}

t_vec3	vadd(t_vec3 ret, t_vec3 vec)
{
	ret.x += vec.x;
	ret.y += vec.y;
	ret.z += vec.z;
	return (ret);
}
