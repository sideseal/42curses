/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/24 20:07:06 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "stdio.h"

char	*gnl_strdup(t_list *node)
{
	int		index;
	char	*string;

	index = 0;
	while (node->backup[index] != '\n'
		&& node->backup[index] != '\0')
		index++;
	string = malloc(sizeof(char) * index + 1);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (*(node->backup) != '\n'
		&& *(node->backup) != '\0')
		string[index++] = *(node->backup)++;
	string[index] = '\0';
	(node->backup)++;
	return (string);
}

char	*gnl_strjoin(t_list *node, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	char	*string;

	len1 = 0;
	while (node->backup[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	string = malloc(sizeof(char) * (len1 + len2) + 1);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (*node->backup)
		string[index++] = *(node->backup)++;
	while (*s2)
		string[index++] = *s2++;
	string[index] = '\0';
	free(node->backup);
	return (string);
}

char	*gnl_lstclear(t_list **node, int fd)
{
	t_list	*cur;
	t_list	*tmp;

	while (*node && (*node)->fd == fd)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	cur = *node;
	while (cur)
	{
		if (cur->next && cur->next->fd == fd)
		{
			tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
		}
		else
			cur = cur->next;
	}
	return (NULL);
}

t_list	*gnl_lstfind(t_list **node, int fd)
{
	t_list	*cur;
	t_list	*new;

	cur = *node;
	while (cur != NULL)
	{
		if (cur->fd == fd)
			return (cur);
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	new = gnl_lstnew(fd);
	if (new == NULL)
		return (NULL);
	if (*node == NULL)
		*node = new;
	else
		cur->next = new;
	return (new);
}

t_list	*gnl_lstnew(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->backup = malloc(sizeof(char));
	if (new->backup == NULL)
		return (NULL);
	new->backup[0] = '\0';
	new->next = NULL;
	return (new);
}
