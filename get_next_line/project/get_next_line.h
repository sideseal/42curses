/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/22 18:29:10 by gychoi           ###   ########.fr       */
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
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strldup(const char *s1, int index1, int index2);

typedef struct s_list
{
	int				fd;
	int				cursor;
	char			*backup;
	struct s_list	*next;
}	t_list;

t_list	*gnl_lstnew(int fd);
t_list	*gnl_lstfind(t_list **node, int fd);
char	*gnl_lstclear(t_list **head);

#endif
