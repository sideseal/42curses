/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:44:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/14 01:52:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_deque *deque_a, t_deque *deque_b)
{
	t_list	*node;

	if (deque_a->head == NULL)
		return ;
	node = deque_a->head;
	if (node->next)
	{
		node->next->prev = NULL;
		deque_a->head = node->next;
	}
	else
	{
		deque_a->head = NULL;
		deque_a->tail = NULL;
	}
	if (deque_b->head)
		deque_b->head->prev = node;
	deque_b->head = node;
	if (deque_b->tail == NULL)
		deque_b->tail = node;
	(deque_a->size)--;
	(deque_b->size)++;
	write(2, "pb\n", 3);
}
