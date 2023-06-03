/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:48:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 16:49:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	scl_add(double t, t_vec3 v)
{
	return (vec3_(t + v.ai, t + v.bj, t + v.ck));
}