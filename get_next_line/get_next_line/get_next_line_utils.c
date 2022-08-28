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

char	*gnl_strdup(char *s1)
{
	size_t	len;
	char	*string;

	if (s1 == NULL)
	{
		string = malloc(sizeof(char));
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	len = 0;
	while (s1[len] != '\0')
		len++;
	string = malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (NULL);
	len = 0;
	while (*s1)
		string[len++] = *s1++;
	string[len] = '\0';
	return (string);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*string;

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	string = malloc(sizeof(char) * (len1 + len2) + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		string[i++] = *s1++;
	while (*s2)
		string[i++] = *s2++;
	string[i] = '\0';
	return (string);
}

char	*gnl_lstclear(t_list **node, int fd)
{
	t_list	*cur;
	t_list	*tmp;

	while (*node && (*node)->fd == fd)
	{
		tmp = (*node)->next;
		free((*node)->backup);
		free(*node);
		*node = tmp;
	}
	cur = *node;
	while (cur)
	{
		if (cur->next && cur->next->fd == fd)
		{
			tmp = cur->next->next;
			free(cur->next->backup);
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
	new->backup = NULL;
	new->next = NULL;
	return (new);
}
