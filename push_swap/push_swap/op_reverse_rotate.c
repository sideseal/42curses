/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:08:14 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/17 20:51:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *deque_a)
{
	t_list	*node;

	if (deque_a->head == deque_a->tail)
		return ;
	node = deque_a->tail;
	deque_a->tail = deque_a->tail->prev;
	deque_a->tail->next = NULL;
	node->next = deque_a->head;
	node->prev = NULL;
	deque_a->head->prev = node;
	deque_a->head = node;
	write(2, "rra\n", 4);
}

void	rrb(t_deque *deque_b)
{
	t_list	*node;

	if (deque_b->head == deque_b->tail)
		return ;
	node = deque_b->tail;
	deque_b->tail = deque_b->tail->prev;
	deque_b->tail->next = NULL;
	node->next = deque_b->head;
	node->prev = NULL;
	deque_b->head->prev = node;
	deque_b->head = node;
	write(2, "rrb\n", 4);
}

void	rrr(t_deque *deque_a, t_deque *deque_b)
{
	rra(deque_a);
	rrb(deque_b);
	write(2, "rrr\n", 4);
}
