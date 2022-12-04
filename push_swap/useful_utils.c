/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:02:17 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 22:47:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	iterr(t_deque *deq)
{
	t_list	*node;

	node = deq->head;
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
void	show_deque(t_deque *a, t_deque *b)
{
	printf("\n\tA FRONT ");
	iterr(a);
	printf("REAR\n");
	printf("\tB FRONT ");
	iterr(b);
	printf("REAR\n\n");
}

#include <stdlib.h>

void	check_leak(void)
{
	system("leaks --list -- checker");
}
// atexit(check_leak)
