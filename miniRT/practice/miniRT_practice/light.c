/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:11 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_light	*light_point(t_point3 origin, t_color3 color, double bright_ratio)
{
	t_light *this;

	this = (t_light*) malloc(sizeof(t_light));
	if (this == NULL)
		return (NULL);
	this->origin = origin;
	this->color = color;
	this->bright_ratio = bright_ratio;
	return (this);
}
