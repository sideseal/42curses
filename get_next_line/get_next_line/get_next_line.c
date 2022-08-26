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

int	search_newline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*make_one_line(t_list *node)
{
	char	*string;
	char	*temp;
	size_t	i;

	i = 0;
	while (node->backup[i] != '\n' && node->backup[i] != '\0')
		i++;
	string = malloc(sizeof(char) * i + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	temp = node->backup;
	while (*(node->backup) != '\n' && *(node->backup) != '\0')
		string[i++] = *(node->backup)++;
	string[i] = '\0';
	node->backup++;
	node->backup = gnl_strdup(node->backup);
	if (node->backup == NULL)
		return (NULL);
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
	free(node->backup);
	if (temp == NULL)
		return (NULL);
	while (readout)
	{
		buffer[BUFFER_SIZE] = '\0';
		line = gnl_strjoin(temp, buffer);
		if (line == NULL)
			return (NULL);
		if (search_newline(line))
		{
			free(temp);
			return (line);
		}
		free(temp);
		temp = line;
		readout = read(node->fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list		*head;
	t_list				*node;
	char				*temp;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (gnl_lstclear(&head, fd));
	node = gnl_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head, fd));
	temp = get_readline(node);
	if (temp == NULL || strlen(temp) < 1) // 임시로...
	{
		free(temp);
		return (gnl_lstclear(&head, fd));
	}
	node->backup = gnl_strdup(temp);
	free(temp);
	if (node->backup == NULL)
		return (gnl_lstclear(&head, fd));
	line = make_one_line(node);
	if (line == NULL || strlen(line) < 1) // 임시로...
	{
		free(line);
		free(node->backup);
		return (gnl_lstclear(&head, fd));
	}
	return (line);
}
