/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 21:04:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// temp function
void	print_scene(t_scene scene)
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		*light;
	t_object	*objects;
	t_cylinder	*cylinder;
	t_plane		*plane;
	t_sphere	*sphere;

	ambient = scene.ambient;
	printf("\n----------\n");
	printf("Ambient\n");
	printf("lighting ratio: %f\n", ambient.lighting_ratio);
	printf("color: %f, %f, %f\n", ambient.color.x, ambient.color.y, ambient.color.z);
	printf("----------\n");
	camera = scene.camera;
	printf("Camera\n");
	printf("coordinate: %f, %f, %f\n", camera.look_from.x, camera.look_from.y, camera.look_from.z);
	printf("normal: %f, %f, %f\n", camera.look_at.x, camera.look_at.y, camera.look_at.z);
	printf("fov: %f\n", camera.h_fov);
	printf("----------\n");
	light = scene.lights->element;
	printf("Light\n");
	printf("coordinate: %f, %f, %f\n", light->origin.x, light->origin.y, light->origin.z);
	printf("bright ratio: %f\n", light->bright_ratio);
	printf("color: %f, %f, %f\n", scene.lights->albedo.x, scene.lights->albedo.y, scene.lights->albedo.z);
	printf("----------\n");
	objects = scene.objects;
	while (objects)
	{
		if (objects->type == CYLINDER)
		{
			cylinder = objects->element;
			printf("Cylinder\n");
			printf("\tcoordinate: %f, %f, %f\n", cylinder->base_center.x, cylinder->base_center.y, cylinder->base_center.z);
			printf("\tnormal: %f, %f, %f\n", cylinder->normal.x, cylinder->normal.y, cylinder->normal.z);
			printf("\tdiameter: %f\n", cylinder->radius);
			printf("\theight: %f\n", cylinder->height);
			printf("\tcolor: %f, %f, %f\n", objects->albedo.x, objects->albedo.y, objects->albedo.z);
		}
		if (objects->type == PLANE)
		{
			plane = objects->element;
			printf("Plane\n");
			printf("\tcoordinate: %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
			printf("\tnormal: %f, %f, %f\n", plane->normal.x, plane->normal.y, plane->normal.z);
			printf("\tcolor: %f, %f, %f\n", objects->albedo.x, objects->albedo.y, objects->albedo.z);
		}
		if (objects->type == SPHERE)
		{
			sphere = objects->element;
			printf("Sphere\n");
			printf("\tcoordinate: %f, %f, %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
			printf("\tradius: %f\n", sphere->radius);
			printf("\tcolor: %f, %f, %f\n", objects->albedo.x, objects->albedo.y, objects->albedo.z);
		}
		objects = objects->next;
	}
	printf("\n----------\n");
}

void	render(t_data *data)
{
	t_scene	scene;
	int		i;
	int		j;

	scene = data->scene;
	print_scene(scene);
	j = scene.canvas.height - 1;
	while (j >= 0)
	{
		printf("rendering... %.2f%%", \
			(float)(scene.canvas.height - j) / scene.canvas.height * 100);
		i = 0;
		while (i < scene.canvas.width)
		{
			rt_mlx_pixel_put(&data->img, i, j, color3_(0.5, 0.3, 0.4));
			i++;
		}
		j--;
		printf("\033[1A\n");
	}
	printf("\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
