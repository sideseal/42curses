/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:52:51 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 22:05:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *deque_a)
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
	write(1, "sa\n", 3);
}

void	sb(t_deque *deque_b)
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
	write(1, "sb\n", 3);
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

void	ss(t_deque *deque_a, t_deque *deque_b)
{
	silent_sa(deque_a);
	silent_sb(deque_b);
	write(1, "ss\n", 3);
}
