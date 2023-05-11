/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmax.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:01:47 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 21:02:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vmax(t_vec3 ret, t_vec3 vec)
{
	if (ret.x < vec.x)
		ret.x = vec.x;
	if (ret.y < vec.y)
		ret.y = vec.y;
	if (ret.z < vec.z)
		ret.z = vec.z;
	return (ret);
}
