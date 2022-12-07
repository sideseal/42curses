/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:12:56 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 18:31:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);

typedef struct s_gnl
{
	int				fd;
	char			*backup;
	struct s_gnl	*next;
}	t_gnl;

t_gnl	*gnl_lstset(t_gnl **head, int fd);
t_gnl	*gnl_lstnew(int fd);
void	*gnl_lstclear(t_gnl **node, int fd);

#endif
