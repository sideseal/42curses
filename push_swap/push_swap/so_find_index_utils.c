/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_find_index_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:28:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/02 18:22:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_min_data(t_deque *deque)
{
	t_list	*node;
	int	min;

	min = deque->head->data;
	node = deque->head;
	while (node)
	{
		if (min > node->data)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	deque_max_data(t_deque *deque)
{
	t_list	*node;
	int	max;

	max = deque->head->data;
	node = deque->head;
	while (node)
	{
		if (max < node->data)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	deque_mid_data(t_deque *deque, int data)
{
	t_list	*node;
	int	mid;

	mid = deque->head->data;
	node = deque->head;
	while (node->next)
	{
		if (data > node->data && data < node->next->data)
			mid = node->next->data;
		node = node->next;
	}
	return (mid);
}

int	check_downward(t_deque *deque, int data)
{
	int	index;
	t_list	*node;

	index = 0;
	node = deque->head;
	while (node)
	{
		if (node->data == data)
			break ;
		index++;
		node = node->next;
	}
	return (index);
}

int	check_upward(t_deque *deque, int data)
{
	int	index;
	t_list	*node;

	index = 0;
	node = deque->tail;
	while (node)
	{
		if (node->data == data)
			break ;
		index++;
		node = node->prev;
	}
	return (index);
}
