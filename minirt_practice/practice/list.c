/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:45:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 20:00:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pracrt.h"
#include "list.h"

void	oadd(t_obj_list **list, t_obj_list *new)
{
	t_obj_list	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_obj_list	*olast(t_obj_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_obj_list	*obj_list(obj_type type, void *element)
{
	t_obj_list	*new;

	new = malloc(sizeof(t_obj_list));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	return (new);
}
