/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:53:34 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:02:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	silent_pa(t_deque *deque_a, t_deque *deque_b)
{
	t_list	*node;

	if (deque_b->head == NULL)
		return ;
	node = deque_b->head;
	if (node->next)
	{
		node->next->prev = NULL;
		deque_b->head = node->next;
	}
	else
	{
		deque_b->head = NULL;
		deque_b->tail = NULL;
	}
	node->next = deque_a->head;
	if (deque_a->head)
		deque_a->head->prev = node;
	deque_a->head = node;
	if (deque_a->tail == NULL)
		deque_a->tail = node;
	(deque_b->size)--;
	(deque_a->size)++;
}

void	silent_pb(t_deque *deque_a, t_deque *deque_b)
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
	node->next = deque_b->head;
	if (deque_b->head)
		deque_b->head->prev = node;
	deque_b->head = node;
	if (deque_b->tail == NULL)
		deque_b->tail = node;
	(deque_a->size)--;
	(deque_b->size)++;
}

void	silent_rra(t_deque *deque_a)
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
}

void	silent_rrb(t_deque *deque_b)
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
}
