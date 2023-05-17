/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmults.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:52:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 16:10:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2mults(t_vec2 ret, double t)
{
	ret.x *= t;
	ret.y *= t;
	return (ret);
}

t_vec3	vmults(t_vec3 ret, double t)
{
	ret.x *= t;
	ret.y *= t;
	ret.z *= t;
	return (ret);
}
