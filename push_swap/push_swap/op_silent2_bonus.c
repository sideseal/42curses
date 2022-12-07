/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_silent_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:57:07 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:02:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	silent_ra(t_deque *deque_a)
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

void	silent_rb(t_deque *deque_b)
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

void	silent_sa(t_deque *deque_a)
{
	t_list	*first;
	t_list	*second;

	if (deque_a->head == deque_a->tail)
		return ;
	first = deque_a->head;
	second = deque_a->head->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	else
		deque_a->tail = first;
	second->next = first;
	second->prev = NULL;
	deque_a->head = second;
}

void	silent_sb(t_deque *deque_b)
{
	t_list	*first;
	t_list	*second;

	if (deque_b->head == deque_b->tail)
		return ;
	first = deque_b->head;
	second = deque_b->head->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	else
		deque_b->tail = first;
	second->next = first;
	second->prev = NULL;
	deque_b->head = second;
}
