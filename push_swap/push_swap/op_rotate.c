/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:10:58 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 21:02:45 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *deque_a)
{
	t_list	*node;

	if (deque_a->head == deque_a->tail)
		return ;
	node = deque_a->head;
	deque_a->head = deque_a->head->next;
	deque_a->head->prev = NULL;
	node->prev = deque_a->tail;
	node->next = NULL;
	deque_a->tail->next = node;
	deque_a->tail = node;
	write(1, "ra\n", 3);
}

void	rb(t_deque *deque_b)
{
	t_list	*node;

	if (deque_b->head == deque_b->tail)
		return ;
	node = deque_b->head;
	deque_b->head = deque_b->head->next;
	deque_b->head->prev = NULL;
	node->prev = deque_b->tail;
	node->next = NULL;
	deque_b->tail->next = node;
	deque_b->tail = node;
	write(1, "rb\n", 3);
}

static void	rr_ra(t_deque *deque_a)
{
	t_list	*node;

	if (deque_a->head == deque_a->tail)
		return ;
	node = deque_a->head;
	deque_a->head = deque_a->head->next;
	deque_a->head->prev = NULL;
	node->prev = deque_a->tail;
	node->next = NULL;
	deque_a->tail->next = node;
	deque_a->tail = node;
}

static void	rr_rb(t_deque *deque_b)
{
	t_list	*node;

	if (deque_b->head == deque_b->tail)
		return ;
	node = deque_b->head;
	deque_b->head = deque_b->head->next;
	deque_b->head->prev = NULL;
	node->prev = deque_b->tail;
	node->next = NULL;
	deque_b->tail->next = node;
	deque_b->tail = node;
}

void	rr(t_deque *deque_a, t_deque *deque_b)
{
	rr_ra(deque_a);
	rr_rb(deque_b);
	write(1, "rr\n", 3);
}
