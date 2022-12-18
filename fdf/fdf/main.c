/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:33:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/19 02:16:55 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *str)
{
	perror(str);
	exit(1);
}

t_point	*fdf_lstnew(int x, int y, int z)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		fdf_error("Error: malloc");
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

t_point	*fdf_lstlast(t_point *point)
{
	if (point == NULL)
		return (NULL);
	while (point->next != NULL)
		point = point->next;
	return (point);
}

void	fdf_lstadd_back(t_point **point, t_point *new)
{
	t_point	*curr;

	if (point == NULL || new == NULL)
		return ;
	if (*point == NULL)
	{
		*point = new;
		return ;
	}
	curr = fdf_lstlast(*point);
	curr->next = new;
}

void	set_point(t_point **point, char *line, int index_y)
{
	char	**vars_x;
	int	index_x;

	// 할당 한 문자열 해제 필요
	vars_x = ft_split(line, ' ');
	index_x = 0;
	while (vars_x[index_x])
	{
		if (vars_x[index_x][0] == '\n')
			break ;
		fdf_lstadd_back(point, fdf_lstnew(index_x, index_y, ft_atoi(vars_x[index_x])));
		index_x++;
	}
}

void	read_file(t_point **point, char *path)
{
	int		fd;
	int		index_y;
	char	*read_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: file open");
	index_y = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		set_point(point, read_line, index_y);
		free(read_line);
		index_y++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_point	*point;
	int		img_width = 720;
	int		img_height = 720;

	if (argc != 2)
		fdf_error("Usage: ./fdf [file]");
	point = NULL;
	read_file(&point, argv[1]);
	return (0);
}
