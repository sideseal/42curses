/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:00 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_canvas canvas_(int height)
{
	t_canvas this;

//	this.aspect_ratio = 16.0/9.0;
	this.aspect_ratio = 4.0/3.0;
	this.height = height;
	this.width = height * this.aspect_ratio;
	return (this);
}
