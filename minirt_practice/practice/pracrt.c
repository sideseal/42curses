/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pracrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:54:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/17 23:08:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "object.h"
#include "structure.h"
#include "utils.h"
#include "ray.h"
#include "light.h"
#include "list.h"
#include "texture.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

int	write_color(t_color3 *pixel_color, double t)
{
	return ((int)t << 24 | (int)(255 * pixel_color->x) << 16 | (int)(255 * pixel_color->y) << 8 | (int)(255 * pixel_color->z));
}

int	trgb(t_color3 *color, double t)
{
	color->x = clamp(color->x, 0, 0.999);
	color->y = clamp(color->y, 0, 0.999);
	color->z = clamp(color->z, 0, 0.999);
	return (write_color(color, t));
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

t_color3	transform_screen_to_world(int x, int y)
{
	double	xscale;
	double	yscale;
	double	aspect;

	xscale = 2.0f / (SCREEN_WIDTH);
	yscale = 2.0f / (SCREEN_HEIGHT);
	aspect = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	return (color3((x * xscale - 1.0f) * aspect, -y * yscale + 1.0f, 0.0f));
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_image		image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "pracRT");
	image.img = mlx_new_image(vars.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.length, &image.endian);

	t_color3	world_pixel;
	t_color3	pixel_color;
	t_ray		pixel_ray;
	t_vec3		raydir;
	t_vec3		eyepos;
	t_light		lt;
	double		dx;

	t_vec3	*temp_image = malloc(sizeof(t_color3) * 4 * 4);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			t_color3	color = color3(0.0f, 0.0f, 0.0f);
			if (i % 4 == 0)
			{
				color.x = 1.0f;
				color.y = 0.0f;
				color.z = 0.0f;
			}
			else if (i % 4 == 1)
			{
				color.x = 0.0f;
				color.y = 1.0f;
				color.z = 0.0f;
			}
			else if (i % 4 == 2)
			{
				color.x = 0.0f;
				color.y = 0.0f;
				color.z = 1.0f;
			}
			else
			{
				color.x = 1.0f;
				color.y = 1.0f;
				color.z = 1.0f;
			}

			color.x *= (1.0f + j) * 0.25f;
			color.y *= (1.0f + j) * 0.25f;
			color.z *= (1.0f + j) * 0.25f;

			temp_image[i + j * 4] = color;
		}
	}

	t_texture	*sample_texture = generate_sample_texture_image(4, 4, temp_image);

	void	*xpm;
	int	img_width;
	int	img_height;
	xpm = mlx_xpm_file_to_image(vars.mlx, "../image/cutecowboycat.xpm", &img_width, &img_height);

	t_texture	*texture = generate_texture_image(img_width, img_height, xpm);

	t_obj_list	*list;

	t_sphere	*sp1;
	sp1 = sphere(point3(0.0f, -0.1f, 1.5f) , 1.0f);
	sp1->obj.amb = color3(0.1f, 0.1f, 0.1f);
	sp1->obj.dif = color3(1.0f, 0.0f, 0.0f);
	sp1->obj.spec = color3(1.0f, 1.0f, 1.0f);
	sp1->obj.alpha = 10.0f;
	sp1->obj.reflection = 0.5f;
	sp1->obj.transparency = 0.0f;

	t_sphere	*sp2;
	sp2 = sphere(point3(1.2f,-0.1f, 0.5f) , 0.4f);
	sp2->obj.amb = color3(0.0f, 0.0f, 0.0f);
	sp2->obj.dif = color3(0.0f, 0.0f, 1.0f);
	sp2->obj.spec = color3(1.0f, 1.0f, 1.0f);
	sp2->obj.alpha = 50.0f;
	sp2->obj.reflection = 0.5f;

//	t_triangle	*tr1;
//	tr1 = triangle(point3(-2.0f, -2.0f, 2.0f), point3(-2.0f, 2.0f, 2.0f), point3(2.0f, 2.0f, 2.0f));
//	tr1->obj.amb = color3(0.0f, 1.0f, 1.0f);
//	tr1->obj.dif = color3(0.0f, 0.0f, 0.0f);
//	tr1->obj.spec = color3(0.0f, 0.0f, 0.0f);

//	t_triangle	*tr2;
//	tr2 = triangle(point3(-2.0f, -1.0f, 0.0f), point3(2.0f, -1.0f, 4.0f), point3(2.0f, -1.0f, 0.0f));
//	tr2->obj.amb = color3(0.2f, 0.2f, 0.2f);
//	tr2->obj.dif = color3(0.8f, 0.8f, 0.8f);
//	tr2->obj.spec = color3(1.0f, 1.0f, 1.0f);
//	tr2->obj.alpha = 50.0f;

	t_square	*sq1;
	sq1 = square(point3(-10.0f, -1.2f, 0.0f), point3(-10.0f,-1.2f, 10.0f), point3(10.0f, -1.2f, 10.0f), point3(10.0f, -1.2f, 0.0f));
	sq1->obj.amb = color3(1.0f, 1.0f, 1.0f);
	sq1->obj.dif = color3(1.0f, 1.0f, 1.0f);
	sq1->obj.spec = color3(1.0f, 1.0f, 1.0f);
	sq1->obj.reflection = 0.5f;
	sq1->obj.amb_texture = sample_texture;
	sq1->obj.dif_texture = sample_texture;

	t_square	*sq2;
	sq2 = square(point3(-5.0f, 3.0f, 2.0f), point3(5.0f, 3.0f, 2.0f), point3(5.0f, -3.0f, 2.0f), point3(-5.0f, -3.0f, 2.0f));
	sq2->obj.amb = color3(1.0f, 1.0f, 1.0f);
	sq2->obj.dif = color3(1.0f, 1.0f, 1.0f);
	sq2->obj.spec = color3(1.0f, 1.0f, 1.0f);
//	sq2->obj.reflection = 0.5f;
	sq2->obj.amb_texture = sample_texture;
	sq2->obj.dif_texture = sample_texture;

	list = obj_list(SP, sp1);
	oadd(&list, obj_list(SP, sp2));
	oadd(&list, obj_list(SQ, sq1));
	oadd(&list, obj_list(SQ, sq2));

	// need to implement viewport for rotate/translate
	eyepos = point3(0.0f, 0.0f, -1.5f);
	lt = light(point3(0.0f, 0.5f, -0.5f));
	//lt = light(point3(0.0f, 1.0f, 0.5f));
	dx = 2.0f / SCREEN_HEIGHT;
	
	for (int j = SCREEN_HEIGHT - 1; j >= 0; j--)
	{
		printf("rendering... %.2f%%", (float)(SCREEN_HEIGHT - j) / SCREEN_HEIGHT * 100);
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			world_pixel = transform_screen_to_world(i, j);
			//raydir = vec3(0, 0, 1);
			pixel_ray = ray(world_pixel, vunit(vsub(world_pixel, eyepos)));
			pixel_color = trace_ray(pixel_ray, list, lt, 5);
//			pixel_color = trace_ray_2x2(eyepos, world_pixel, dx, 3, list, lt);
			my_mlx_pixel_put(&image, i, j, trgb(&pixel_color, 1.0));
		}
		printf("\033[1A\n");
	}

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);

//	void	*xpm;
//	int	img_width;
//	int	img_height;
//	xpm = mlx_xpm_file_to_image(vars.mlx, "../image/cutecowboycat.xpm", &img_width, &img_height);
//	mlx_put_image_to_window(vars.mlx, vars.win, xpm, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
