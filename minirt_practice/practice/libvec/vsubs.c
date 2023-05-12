/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:51:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 20:52:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vsubs(t_vec3 ret, double x, double y, double z)
{
	ret.x -= x;
	ret.y -= y;
	ret.z -= z;
	return (ret);
}