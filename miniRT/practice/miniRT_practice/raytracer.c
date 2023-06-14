/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:15 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:16 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_raytracer	raytracer_(const int width, const int height)
{
	t_raytracer this;

	this.width = width;
	this.height = height;
	return this;
}

t_vec3	screen_to_world(t_vec2 pos_screen, t_raytracer* raytracer)
{
	double x_scale = 2.0 / (raytracer->width - 1);
	double y_scale = 2.0 / (raytracer->height - 1);
	double aspect = (double) raytracer->width / raytracer->height;

	return vec3_((pos_screen.x * x_scale - 1.0) * aspect,
				-pos_screen.y * y_scale + 1.0, 0.0);
}

/*
t_vec3 trace_ray(t_ray* ray, t_raytracer* raytracer)
{
	t_hit hit = intersect_ray_collision(ray, &raytracer->sphere);

	if(hit.t < 0.0)
	{
		return vec3_(0.0, 0.0, 0.0);
	}
	else
	{
//		return scl_mul(raytracer->sphere.color, hit.t);
		return vec3_(1.0, 0.0, 0.0);
	}
}
*/
/*

void render()
{
	const int image_width = 1280;
	const int image_height = 720;

	printf("P3\n%d %d\n255\n", image_width, image_height);

	t_raytracer raytracer = raytracer_(image_width, image_height);

	t_vec3* pixels = malloc(sizeof(t_vec3) * image_width * image_height);
	for (int x = 0; x < image_width * image_height; ++x)
		pixels[x] = color(0.0, 0.0, 0.25);

	for (int y = 0; y < image_height; ++y) {
		for (int x = 0; x < image_width; ++x) {

			t_vec3 pixel_pos_world = screen_to_world(vec2_(x, y), &raytracer);

			t_vec3 ray_dir = vec3_(0.0, 0.0, -1.0);

			t_ray pixel_ray = ray_(pixel_pos_world, ray_dir);
			pixels[x + y * image_width] = trace_ray(&pixel_ray, &raytracer);
//			t_vec3 * cur = &pixels[x+y*image_width];
//			printf("%f %f %f\n", cur->r, cur->g, cur->b);
		}
	}

	for (int y = 0; y < image_height; ++y) {
		for (int x = 0; x < image_width; ++x) {
			int ir = 255.999 * pixels->r;
			int ig = 255.999 * pixels->g;
			int ib = 255.999 * pixels->b;
			printf("%d %d %d\n", ir, ig, ib);
		}
	}

}
*/
