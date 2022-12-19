/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:24:06 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/20 01:27:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*fdf_lstnew(int x, int y, int z)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		fdf_error("Error: malloc");
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

t_point	*fdf_lstlast(t_point *point)
{
	if (!point)
		return (NULL);
	while (point->next != NULL)
		point = point->next;
	return (point);
}

void	fdf_lstadd_back(t_point **point, t_point *new)
{
	t_point	*curr;

	if (!point || !new)
		return ;
	if (!*point)
	{
		*point = new;
		return ;
	}
	curr = fdf_lstlast(*point);
	curr->next = new;
}

void	fdf_lstclear(t_point **point)
{
	t_point	*next;
	t_point	*node;

	node = *point;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(node);
}
