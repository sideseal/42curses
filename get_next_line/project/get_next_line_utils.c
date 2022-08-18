/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/18 20:22:20 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstfind_fd(t_list *node, int fd)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->fd == fd)
			break;
		if (node->next == NULL)
		{
			node->next = gnl_lstnew(fd);
			if (!node->next)
				return (NULL);
		}
		node = node->next;
	}
	return (node);
}

t_list	*ft_lstnew_fd(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buffer = NULL;
	new->next = NULL;
	return (new);
}
