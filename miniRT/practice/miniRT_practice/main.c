/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:19 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:20 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	init_mlx_n_img(t_vars *vars)
{
	const int width = vars->scene->canvas.width;
	const int height = vars->scene->canvas.height;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "miniRT");
	vars->img.img = mlx_new_image(vars->mlx, width, height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	return ;
}

void	init(int argc, char ***argv, t_vars *vars)
{
	vars->scene = scene_();
	init_mlx_n_img(vars);
	(void) argc;
	(void) argv;
//	init_fractal(argc, argv, vars);

	get_minirt_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

void c()
{
	system("leaks miniRT");
}

int main()
{
//	t_scene* scene = scene_();
//
//	render(scene);

//	atexit(c);

	t_vars	vars;

	char** argv = NULL;
	int argc = 0;

	init(argc, &argv, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, red_cross, vars.mlx);
	mlx_loop(vars.mlx);
//	free_scene(vars.scene);

	return (0);
}
