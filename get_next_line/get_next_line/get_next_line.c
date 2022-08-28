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

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	search_newline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*make_one_line(t_list *node)
{
	char	*string;
	char	*temp;
	size_t	len;
	size_t	i;

	len = search_newline(node->backup);
	if (len < 1)
		len = gnl_strlen(node->backup);
	string = malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (NULL);
	temp = node->backup;
	i = 0;
	while (i < len)
		string[i++] = *(node->backup)++;
	string[i] = '\0';
	node->backup = gnl_strdup(node->backup);
	if (node->backup == NULL)
	{
		free(string);
		free(temp);
		return (NULL);
	}
	free(temp);
	return (string);
}

char	*get_readline(t_list *node)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	char	*line;
	ssize_t	readout;

	readout = read(node->fd, buffer, BUFFER_SIZE);
	if (readout < 0)
		return (NULL);
	temp = gnl_strdup(node->backup);
	if (temp == NULL)
		return (NULL);
	free(node->backup);
	while (readout)
	{
		buffer[readout] = '\0';
		line = gnl_strjoin(temp, buffer);
		if (line == NULL)
			return (NULL);
		free(temp);
		if (search_newline(line))
			return (line);
		temp = line;
		readout = read(node->fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list				*node;
	char				*line;
	char				*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = gnl_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head, fd));
	temp = node->backup;
	node->backup = get_readline(node);
	if (node->backup == NULL)
	{
		free(temp);
		return (gnl_lstclear(&head, fd));
	}
	if (gnl_strlen(node->backup) < 1)
		return (gnl_lstclear(&head, fd));
	line = make_one_line(node);
	if (line == NULL)
		return (gnl_lstclear(&head, fd));
	return (line);
}
