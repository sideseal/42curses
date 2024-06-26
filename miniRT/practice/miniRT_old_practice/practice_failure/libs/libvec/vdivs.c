/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdivs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:53:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 20:53:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vdivs(t_vec3 ret, double t)
{
	ret.x *= (1 / t);
	ret.y *= (1 / t);
	ret.z *= (1 / t);
	return (ret);
}
