/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:41 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENUM_H
#define MINIRT_ENUM_H

enum e_root
{
	INVALID_ROOT = -1,
};

enum e_bool
{
	FALSE,
	TRUE,
};

enum e_object_type
{
	CONE,
	PLANE,
	SPHERE,
	CYLINDER,
	OBJECT_TYPE_SIZE,
};

enum e_component
{
	TOP,
	BASE,
};

enum e_light
{
	LIGHT_POINT = 1,
};

enum e_key
{
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
	DOWN_NUM = 84,
	UP_NUM = 91,
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	T = 17,
	V = 9,
};


#endif //MINIRT_ENUM_H
