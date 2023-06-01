/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:42:48 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 16:57:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3	ret;

	ret.ai = u.bj * v.ck - u.ck * v.bj;
	ret.bj = u.ck * v.ai - u.ai * v.ck;
	ret.ck = u.ai * v.bj - u.bj * v.ai;
	return (ret);
}
