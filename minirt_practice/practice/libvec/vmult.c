/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmult.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:52:16 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/16 16:43:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2mult(t_vec2 ret, t_vec2 vec)
{
	ret.u *= vec.u;
	ret.v *= vec.v;
	return (ret);
}

t_vec3	vmult(t_vec3 ret, t_vec3 vec)
{
	ret.x *= vec.x;
	ret.y *= vec.y;
	ret.z *= vec.z;
	return (ret);
}
