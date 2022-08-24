/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:15:00 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/24 20:09:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "string.h"
#include "stdio.h"

size_t	gnl_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\n' && s[index] != '\0')
		index++;
	return (index);
}

int	check_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

// strdup 함수 고쳐야 함.
char	*read_backup(t_list *node)
{
	char	*line;

	line = gnl_strdup(node);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*make_backup(t_list *node)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	readout;

	while (!check_newline(node->backup))
	{
		readout = read(node->fd, buffer, BUFFER_SIZE);
		if (readout < 0)
			return (NULL);
		if (readout == 0)
			break ;
		buffer[readout] = '\0';
		printf("go into strjoin...\n");
		node->backup = gnl_strjoin(node, buffer);
		if (node->backup == NULL)
			return (NULL);
	}
	printf("OUT\n");
	return (node->backup);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list				*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (gnl_lstclear(&head, fd));
	node = gnl_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head, fd));
	node->backup = make_backup(node);
	if (node->backup == NULL || gnl_strlen(node->backup) < 1)
		return (gnl_lstclear(&head, fd));
	line = read_backup(node);
	if (line == NULL)
		return (gnl_lstclear(&head, fd));
	return (line);
}
