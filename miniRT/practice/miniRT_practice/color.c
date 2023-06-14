/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:21:16 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:21:18 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	write_color(t_color3 color)
{
	for(int i=0; i<3; ++i)
		printf("%d ", (int) (255.999 * color.arr[i]));
	printf("\n");
	return ;
}

int	create_trgb(t_color3 color)
{
	const unsigned char t = 0;
	const unsigned char r = 255.99 * color.r;
	const unsigned char g = 255.99 * color.g;
	const unsigned char b = 255.99 * color.b;

	return (*(int *)(unsigned char [4]){b, g, r, t});
}
