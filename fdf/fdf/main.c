/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/13 21:03:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_ctx	*ctx;
	t_fdf	*fdf;
	int		img_width;
	int		img_height;

	// argc 3개 이상인 경우도 처리할 것.
	if (argc < 2)
		return (0);
	img_width = 720;
	img_height = 720;
	ctx = init_ctx(argv[1], img_width, img_height);
	fdf = init_fdf(ctx, img_width, img_height);
	printf("width: %d, height: %d\n", ctx->width, ctx->height);
	for (int i = 0; i < 9; i++)
		printf("line : %s\n", ctx->map[i]);
	return (0);
}
