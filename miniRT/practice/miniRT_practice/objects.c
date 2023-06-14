/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:22:24 by salee2            #+#    #+#             */
/*   Updated: 2023/05/24 20:22:25 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

t_object *object_(t_object_type type, void* element, t_color3 albedo)
{
	t_object* this;

	this = (t_object*) malloc(sizeof(t_object));
	if (this == NULL)
		return (NULL);
	this->type = type;
	this->element = element;
	this->next = NULL;
	this->albedo = albedo;
	return (this);
}

void	append_object(t_object **list, t_object* object)
{
	t_object* cur;

	if(*list == NULL)
	{
		*list = object;
		return ;
	}
	cur = *list;
	while(cur->next)
		cur = cur->next;
	cur->next = object;
	return ;
}

t_object *back_object(t_object *list)
{
	if(list == NULL)
		return (NULL);
	while(list->next)
		list = list->next;
	return (list);
}
