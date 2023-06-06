/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:03:50 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/06 20:52:51 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_del(data->mlx);
}

static void	_free_objects(t_object *objects)
{
	t_object	*cur;

	if (objects == NULL)
		return ;
	cur = objects;
	while (cur)
	{
		free(cur->element);
		cur = cur->next;
	}
	free(objects);
}

void	free_struct(t_data *data)
{
	_free_mlx(data);
	_free_objects(data->scene.lights);
	_free_objects(data->scene.objects);
	free(data);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
