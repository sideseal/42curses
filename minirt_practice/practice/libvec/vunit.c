/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vunit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:54:17 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 21:00:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	vunit(t_vec3 ret)
{
	double	len;

	len = vlen(ret);
	if (len == 0)
		write(2, "warning: division by zero\n", 26);
	ret.x /= len;
	ret.y /= len;
	ret.z /= len;
	return (ret);
}
