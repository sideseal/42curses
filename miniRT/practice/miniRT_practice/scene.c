/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:23:01 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:23:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_scene *scene_(void)
{
	t_scene		*scene;
	t_object	*objects;
	t_object	*lights;
	double		ambient_intensity;

	scene = (t_scene*) malloc(sizeof(t_scene));
	if(scene == NULL)
		return (NULL);
	scene->canvas = canvas_(500);
	scene->camera = camera_(&scene->canvas, point3_(0, 0, 10), point3_(0,0,-1), 70);

//	objects = object_(CONE, cone_(point3_(0, 0, 0), vec3_(0, -1,0 ), 2, 4),color3_(0, 0, 1));

	objects = object_(CYLINDER, cylinder_(point3_(0, 0, 3), vec3_(1,0,0), 3, 1), color3_(1,0,0));
//	append_object(&objects, object_(CYLINDER, cylinder_(point3_(0, 0, 0), vec3_(0,-1,0), 3, 1), color3_(0,1,0)));
	append_object(&objects, object_(CONE, cone_(point3_(0, 0, 0), vec3_(0,1,0), 3, 5), color3_(0,0,1)));

//	objects = object_(CYLINDER, cylinder_(point3_(0, 0, 0), vec3_(0,1,0), 3, 1), color3_(1,0,0));
	append_object(&objects, object_(SPHERE,sphere_(point3_(0, 0, 0), 2), color3_(0.1,1,0)));

//	objects = object_(SPHERE, sphere_(point3_(0, -0, 0), 2), color3_(0.5,0,0));
//	append_object(&objects, object_(CYLINDER, cylinder_(point3_(0, 0, 0), vec3_(0,1,0), 3, 1), color3_(1,0,0)));
//	append_object(&objects, object_(CONE, cone_(point3_(0, 0, 0), vec3_(0,0,1), 2, 4), color3_(0,0,1)));

//	objects = object_(CONE, cone_(point3_(0, 0, 0), vec3_(0, 0, -1), 2, 4),color3_(0, 0, 1));
//	append_object(&objects, object_(PLANE,plane_(point3_(0, 0, 0),vec3_(1, 1, 0)), color3_(0, 0, 1)));
//	objects = object_(CONE, cone_(point3_(0, 0, 0), vec3_(0,0,1), 2, 6), color3_(0.5,0,0));
//	append_object(&objects, object_(CONE, cone_(point3_(0, 0, 0), vec3_(0,0,1), 2, 4), color3_(0,0,1)));
//	append_object(&objects, object_(CYLINDER, cylinder_(point3_(0, 0, 0), vec3_(0,1,0), 3, 1), color3_(1,0,0)));
//	objects = object_(CYLINDER, cylinder_(point3_(0, 0, 0), vec3_(0,1,0), 3, 1), color3_(1,0,0));

//	objects = object_(SPHERE, sphere_(point3_(2.0, 0.0, -5), 2), color3_(1,0,0));
//	append_object(&objects, object_(SPHERE, sphere_(point3_(0, -0, 0), 2), color3_(0.1,1,0)) );
//	append_object(&objects, object_(SPHERE, sphere_(point3_(0.0, -500, 0), 498), color3_(1, 1, 1)));
//	append_object(&objects, object_(CYLINDER, cylinder_(point3_(2, -1, -5), vec3_(1, 0,0), 2, 2),color3_(1, 0, 0)));

//	append_object(&objects, object_(PLANE,plane_(point3_(0, 0, -50),vec3_(0, 0,1)), color3_(0, 0.5,0.5 )));
//	append_object(&objects, object_(PLANE,plane_(point3_(-30, 0, 0), vec3_(-1, 0, 0)), color3_(0, 0.7, 0.3)));
//	append_object(&objects, object_(PLANE,plane_(point3_(0, -30, 0),vec3_(0, 1,0)), color3_(0, 0.6, 0.4)));
//	append_object(&objects, object_(PLANE,plane_(point3_(30, 0, 0), vec3_(1,0,0)), color3_(0, 0.4, 0.6)));
//	append_object(&objects, object_(PLANE,plane_(point3_(0, 30, 0),vec3_(0, 1,0)), color3_(0, 0.3, 0.7)));

//	append_object(&objects, object_(PLANE,plane_(point3_(0, 0, 0),vec3_(0, 0, 1)), color3_(0, 0, 0)));

	scene->objects = objects;
	lights = NULL;
	lights = object_(LIGHT_POINT, light_point(point3_(0, 20,0  ), color3_(1, 1, 1), 0.5), color3_(0, 0, 0));
//	append_object(&lights,object_(LIGHT_POINT, light_point(point3_(-10, -10, 0 ), color3_(1, 1, 1), 0.5), color3_(0, 0, 0)));
//	append_object(&lights,object_(LIGHT_POINT, light_point(point3_(0, 0,10 ), color3_(1, 1, 1), 0.5), color3_(0, 0, 0)));
//	append_object(&lights,object_(LIGHT_POINT, light_point(point3_(0, 0,-10 ), color3_(1, 1, 1), 0.5), color3_(0, 0, 0)));

	scene->light = lights;
	ambient_intensity = 0.1;
	scene->ambient = scl_mul(ambient_intensity, color3_(1, 1, 1));
	return (scene);
}
