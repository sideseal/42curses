/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:51:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 16:07:27 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2subs(t_vec2 ret, double x, double y)
{
	ret.x -= x;
	ret.y -= y;
	return (ret);
}

t_vec3	vsubs(t_vec3 ret, double x, double y, double z)
{
	ret.x -= x;
	ret.y -= y;
	ret.z -= z;
	return (ret);
}
