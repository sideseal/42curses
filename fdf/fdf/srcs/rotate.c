/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:08:39 by gychoi            #+#    #+#             */
/*   Updated: 2023/01/01 20:09:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = point->x;
	new_y = (point->y * cos(theta)) + (point->z * sin(theta) * -1);
	new_z = (point->y * sin(theta)) + (point->z * cos(theta));
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}

void	rotate_y(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = (point->x * cos(theta)) + (point->z * sin(theta));
	new_y = point->y;
	new_z = (point->x * sin(theta) * -1) + (point->z * cos(theta));
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}

void	rotate_z(t_point *point, double theta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = (point->x * cos(theta)) + (point->y * sin(theta) * -1);
	new_y = (point->x * sin(theta)) + (point->y * cos(theta));
	new_z = point->z;
	point->x = new_x;
	point->y = new_y;
	point->z = new_z;
}
