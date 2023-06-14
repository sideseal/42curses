/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:52 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H

#include "define.h"
#include "enum.h"
#include "typedef.h"
#include "include.h"

t_vec2 vec2_(double x, double y);

t_vec3 vec3_(double ai, double bj, double ck);

t_vec3 add(t_vec3 u, t_vec3 v);

t_vec3 sub(t_vec3 u, t_vec3 v);

t_vec3 scl_mul(double k, t_vec3 vector);

double mag_sq(t_vec3 vec);

double mag(t_vec3 vec);

t_vec3 norm(t_vec3 vector);

double dot(t_vec3 u, t_vec3 v);

t_vec3 cross(t_vec3 u, t_vec3 v);



t_sphere* sphere_(t_point3 center, double radius);

//t_hit intersect_ray_collision(t_ray* ray, t_sphere* sphere);


t_raytracer raytracer_(const int width, const int height);

t_vec3 screen_to_world(t_vec2 pos_screen, t_raytracer* raytracer);

t_point3 point3_(double x, double y, double z);

t_color3 color3_(double r, double g, double b);


t_ray ray_(t_point3 origin, t_vec3 dir);

t_vec3 ray_at(double t, t_ray* ray);



int	ray_color(t_scene* scene);


t_bool intersect_ray_sphere(t_object* object, t_ray* ray, t_hit* hit);


t_canvas canvas_(int height);

//t_camera camera_(t_canvas* canvas, t_vec3 origin);

t_camera
camera_(t_canvas* canvas, t_point3 look_from, t_point3 look_at, double h_fov);

t_ray primary_ray(t_camera* cam, t_vec2 xy);

//t_ray primary_ray(t_camera* cam, double u, double v);

void set_hit_face_normal(t_ray* ray, t_hit* hit);


t_object* object_(t_object_type type, void* element, t_color3 albedo);


void append_object(t_object** list, t_object* object);

t_object* back_object(t_object* list);

t_bool hit_objects(t_object* objects, t_ray* ray, t_hit* hit);



t_light* light_point(t_point3 origin, t_color3 color, double bright_ratio);

t_hit hit_(double t_max);

//t_hit hit_(void);


t_vec3 hadam_prod(t_vec3 u, t_vec3 v);

t_vec3 elem_min(t_vec3 u, t_vec3 v);

t_color3 phong_lighting(t_scene* scene);

t_color3 point_light_get(t_scene* scene, t_light* light);

void render(t_scene* scene);


t_cylinder*
cylinder_(t_point3 center, t_vec3 dir, double radius, double height);

t_bool intersect_ray_cylinder(t_object* object, t_ray* ray, t_hit* hit);


t_plane* plane_(t_point3 point, t_vec3 normal);

t_bool intersect_ray_plane(t_object* object, t_ray* ray, t_hit* hit);

t_scene* scene_(void);

void write_color(t_color3 color);

void update_hit(t_ray* ray, t_hit* hit, t_point3 center, t_color3 albedo);

t_bool intersect_cylinder_base(t_object* object, t_ray* ray, t_hit* hit,
							   enum e_component type);

t_bool intersect_cylinder_surface(t_object* object, t_ray* ray, t_hit* hit);

t_cone* cone_(t_point3 center, t_vec3 dir, double radius, double height);

t_bool intersect_cone_surface(t_object* object, t_ray* ray, t_hit* hit);

t_bool intersect_ray_cone(t_object* object, t_ray* ray, t_hit* hit);

t_bool intersect_cone_base(t_object* object, t_ray* ray, t_hit* hit);

t_bool intersect_cone_surface(t_object* object, t_ray* ray, t_hit* hit);

t_vec3 clamp_vec3(t_vec3 value, t_vec3 min, t_vec3 max);


int red_cross(void);

int key_hook(int keycode, t_vars* vars);

void get_minirt_image(t_vars* vars);

int ft_atoi(const char* str, int* is_error, double* sign);

double ft_atof(const char* str);

int ft_isdigit(int c);

int create_trgb(t_color3 color);

t_color3 get_diffuse(t_vec3 normal, t_vec3 light_dir, t_color3 color);

t_color3 get_specular(t_scene* scene, t_vec3 light_dir, t_color3 color);

void free_scene(t_scene* scene);



#endif //MINIRT_MINIRT_H
