/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:58:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 19:55:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	count_tokens(char **tokens)
{
	size_t	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

static char	**_tokenize(t_data *data, char *line)
{
	char	**tokens;
	char	**new_tokens;
	char	*info;
	size_t	count;

	tokens = ft_split(line, ' ');
	count = count_tokens(tokens);
	new_tokens = rt_malloc(sizeof(char *) * (count + 1), data);
	new_tokens[count] = NULL;
	count = 0;
	while (tokens[count])
	{
		info = ft_strtrim(tokens[count], "\n");
		free(tokens[count]);
		if (ft_strlen(info) < 1)
			new_tokens[count] = NULL;
		else
			new_tokens[count] = ft_strdup(info);
		free(info);
		count++;
	}
	free(tokens);
	return (new_tokens);
}

void	read_file(t_data *data, char *file)
{
	int		fd;
	char	*read_line;
	char	**tokens;

	fd = rt_open(file, O_RDONLY, data);
	while (TRUE)
	{
		tokens = NULL;
		read_line = get_next_line(fd);
		if (read_line == NULL)
			break ;
		tokens = _tokenize(data, read_line);
		free(read_line);
		set_data(tokens, data);
		free_tokens(tokens);
	}
	rt_close(fd, data);
}
