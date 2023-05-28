/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:08:55 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 16:10:47 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libvec.h"

t_vec2	vec2(double x, double y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}