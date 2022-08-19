/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/19 17:37:38 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 지우기!
#include <stdio.h>

t_list	*gnl_lstclear(t_list **head)
{
	t_list	*next;

	if (head == NULL)
		return (NULL);
	while (*head != NULL)
	{
		next = (*head)->next;
		if ((*head)->temp != NULL)
			free((*head)->temp);
		free(*head);
		*head = next;
	}
	return (NULL);
}

t_list	*fd_lstfind(t_list **node, int fd)
{
	if (*node == NULL)
	{
		*node = fd_lstnew(fd);
		if (*node == NULL)
			return (NULL);
	}
	while (*node)
	{
		if ((*node)->fd == fd)
			break ;
		if ((*node)->next == NULL)
		{
			(*node)->next = fd_lstnew(fd);
			if ((*node)->next == NULL)
				return (NULL);
		}
		*node = (*node)->next;
	}
	return (*node);
}

t_list	*fd_lstnew(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->temp = NULL;
	new->next = NULL;
	return (new);
}
