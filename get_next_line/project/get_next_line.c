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

// 한 줄 읽는 함수.
// 1. 만약 안에 개행이 있다면, 개행 전까지 라인을 반환하고 나머지는 구조체에 저장.
// 2. 만약 안에 개행이 없다면, 개행이 나올 때까지 read를 반복.
// 3. 만약 파일이 끝이거나 오류가 난다면, 해당 구조체를 free하고 NULL을 반환.
char	*read_line(t_list *node)
{
	char	*buffer[BUFFER_SIZE + 1];
	char	*temp;
	char	*line;
	int		idx;
	ssize_t	read_bytes;
	// 뭔가 X됨을 의미하는 최대 한도의 변수 선언 ㅋㅋ...
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*head_start;
	t_list			*node;
	char			*line;

	printf("\n\n======start=======\n\n");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (gnl_lstclear(&head_start));
	head_start = head;
	node = fd_lstfind(&head, fd);
	if (node == NULL)
		return (gnl_lstclear(&head_start));
	line = read_line(node);
	if (line == NULL)
		return (gnl_lstclear(&head_start));
	return (line);
}
