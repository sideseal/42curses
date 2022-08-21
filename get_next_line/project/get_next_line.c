/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:15:00 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/19 19:49:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 지우기!
#include <stdio.h>
#include <string.h>

int	has_newline(char *buffer)
{
	int	index;
	
	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*read_backup(t_list *node)
{
	printf("read from buffer: %s\n", node->backup);
	return (NULL);
}

char	*read_file(t_list *node)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	readout;

	while (1)
	{
		readout = read(node->fd, buffer, BUFFER_SIZE);
		if (readout < 0)
			return (NULL);
		if (readout == 0)
			break ;
		buffer[readout] = '\0';
		temp = node->backup;
		node->backup = gnl_strjoin(temp, buffer);
		if (node->backup == NULL)
			return (NULL);
		free(temp);
		if (has_newline(buffer))
			break ;
	}
	return (node->backup);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list			*node;
	char			*line;

	printf("\n\n======start=======\n\n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (gnl_lstclear(&head));
	node = gnl_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head));
	if (node->length < 1)
		node->backup = read_file(node);
	line = read_backup(node);
	// if (line == NULL)
	// 	return (gnl_lstclear(&head));
	return (line);
}
