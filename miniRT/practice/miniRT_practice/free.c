/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:41:09 by salee2            #+#    #+#             */
/*   Updated: 2023/05/31 17:41:10 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

void	free_objects(t_object *objects)
{
	t_object *cur;

	cur = objects;
	while(cur)
	{
		free(cur->element);
		cur = cur->next;
	}
	return ;
}

void	free_scene(t_scene *scene)
{
	free_objects(scene->light);
	free_objects(scene->objects);
	free(scene);
	return ;
}

