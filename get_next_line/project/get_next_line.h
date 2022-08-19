/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/19 19:49:40 by gychoi           ###   ########.fr       */
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

typedef struct s_list
{
	int				fd;
	char			*temp;
	struct s_list	*next;
}	t_list;

t_list	*fd_lstnew(int fd);
t_list	*fd_lstfind(t_list **node, int fd);
t_list	*gnl_lstclear(t_list **head);

#endif
