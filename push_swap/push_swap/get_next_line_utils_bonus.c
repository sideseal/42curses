/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:12:23 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:05:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*gnl_lstclear(t_gnl **head, int fd)
{
	t_gnl	*cur;
	t_gnl	*tmp;

	if (*head != NULL && (*head)->fd == fd)
	{
		tmp = (*head)->next;
		free((*head)->backup);
		free(*head);
		*head = tmp;
	}
	cur = *head;
	while (cur != NULL)
	{
		if (cur->next != NULL && cur->next->fd == fd)
		{
			tmp = cur->next->next;
			free(cur->next->backup);
			free(cur->next);
			cur->next = tmp;
			break ;
		}
		cur = cur->next;
	}
	return (NULL);
}

t_gnl	*gnl_lstset(t_gnl **head, int fd)
{
	t_gnl	*cur;

	if (*head == NULL)
	{
		*head = gnl_lstnew(fd);
		return (*head);
	}
	cur = *head;
	while (cur != NULL)
	{
		if (cur->fd == fd)
			break ;
		if (cur->next == NULL)
		{
			cur->next = gnl_lstnew(fd);
			return (cur->next);
		}
		cur = cur->next;
	}
	return (cur);
}

t_gnl	*gnl_lstnew(int fd)
{
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->backup = NULL;
	new->next = NULL;
	return (new);
}
