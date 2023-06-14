/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mag_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:42:27 by salee2            #+#    #+#             */
/*   Updated: 2023/06/02 16:42:29 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

double	mag_sq(t_vec3 vec)
{
	return (vec.ai * vec.ai + vec.bj * vec.bj + vec.ck * vec.ck);
}

double	mag(t_vec3 vec)
{
	return (sqrt(mag_sq(vec)));
}

t_vec3	norm(t_vec3 vector)
{
	const double	m = mag(vector);

	return (scl_mul(1.0 / m, vector));
}
