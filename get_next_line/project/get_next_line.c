/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:15:00 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/22 18:29:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 지우기!
#include <stdio.h>
#include <string.h>

int	check_newline(char *buffer, int index)
{
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (index + 1);
		index++;
	}
	return (0);
}

char	*read_backup(t_list *node)
{
	int		newline_index;
	char	*line;

	newline_index = check_newline(node->backup, node->cursor);
	printf("string: %s\n\n", node->backup);
	printf("newline index, cursor: %d, %d\n\n", newline_index, node->cursor);
	if (!newline_index)
	{
		// 이 부분 바꿔야 함.
		node->backup[0] = '\0';
		node->cursor = 0;
		return (node->backup);
	}
	line = gnl_strldup(node->backup, node->cursor, newline_index);
	if (line == NULL)
		return (NULL);
	node->cursor = newline_index;
	return (line);
}

char	*make_backup(t_list *node)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	readout;

	while (1)
	{
		readout = read(node->fd, buffer, BUFFER_SIZE);
		if (readout < 0)
			return (NULL);
		// 맨 마지막에 개행이 자동으로 추가되나?
		if (readout == 0)
			return (NULL);
		buffer[readout] = '\0';
		temp = node->backup;
		node->backup = gnl_strjoin(temp, buffer);
		if (node->backup == NULL)
			return (NULL);
		free(temp);
		if (check_newline(buffer, 0))
			break ;
	}
	return (node->backup);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list				*node;
	char				*line;

	printf("\n\n======start=======\n\n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (gnl_lstclear(&head));
	node = gnl_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head));
	if (!node->cursor)
	{
		node->backup = make_backup(node);
		if (node->backup == NULL)
			return (gnl_lstclear(&head));
	}
	line = read_backup(node);
	if (line == NULL)
		return (gnl_lstclear(&head));
	return (line);
}
