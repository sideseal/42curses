/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:01:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 20:28:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object_(t_obj_type type, void *elem, t_color3 albd, t_data *data)
{
	t_object	*object;

	object = rt_malloc(sizeof(t_object), data);
	object->element = elem;
	object->next = NULL;
	object->albedo = albd;
	object->type = type;
	return (object);
}

void	append(t_object **list, t_object *object)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = object;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = object;
}
