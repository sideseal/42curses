/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:53:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/27 22:02:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_utils.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == 0)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_object	*olast(t_object *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}
