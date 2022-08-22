/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/22 18:29:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 지우기!
#include <stdio.h>
// strjoin에 마지막 + 1 해줘야 하나?
// char const, const char 차이?

char	*gnl_strldup(const char *s1, int index1, int index2)
{
	int		len;
	char	*string;

	len = index1;
	while (len < index2)
		len++;
	string = malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (NULL);
	len = 0;
	while (index1 < index2)
		string[len++] = s1[index1++];
	string[len] = '\0';
	return (string);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	char	*string;

	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	string = malloc(sizeof(char) * (len1 + len2));
	if (string == NULL)
		return (NULL);
	index = 0;
	while (*s1)
		string[index++] = *s1++;
	while (*s2)
		string[index++] = *s2++;
	string[index] = '\0';
	return (string);
}

char	*gnl_lstclear(t_list **node)
{
	t_list	*next;

	while (*node != NULL)
	{
		next = (*node)->next;
		free((*node)->backup);
		free(*node);
		*node = next;
	}
	return (NULL);
}

t_list	*gnl_lstfind(t_list **node, int fd)
{
	if (*node == NULL)
	{
		*node = gnl_lstnew(fd);
		if (*node == NULL)
			return (NULL);
	}
	while (*node)
	{
		if ((*node)->fd == fd)
			break ;
		if ((*node)->next == NULL)
		{
			(*node)->next = gnl_lstnew(fd);
			if ((*node)->next == NULL)
				return (NULL);
		}
		*node = (*node)->next;
	}
	return (*node);
}

t_list	*gnl_lstnew(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->backup = malloc(sizeof(char));
	if (new->backup == NULL)
		return (NULL);
	new->backup[0] = '\0';
	new->cursor = 0;
	new->next = NULL;
	return (new);
}
