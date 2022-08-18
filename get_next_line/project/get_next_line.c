/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:15:00 by gychoi            #+#    #+#             */
/*   Updated: 2022/08/18 20:35:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE < 1)
	// 리스트 순회하며 해제해야 함.
		return (NULL);
	// 뭔가 이상함...
	head = ft_lstnew_fd(fd);
	node = ft_lstfind_fd(head, fd);
	if (!head || !node)
		return (NULL);
	// newline이 나올 때까지 버퍼 읽기.
	
	return (NULL);
}
