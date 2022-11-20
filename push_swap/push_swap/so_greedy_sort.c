/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_greedy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:09:43 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/20 23:39:26 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

void	recursive(t_deque *deque_a, t_deque *deque_b, int tail_data)
{
	t_list	*node;

	node = deque_a->head;
	//printf("node data: %d\n", node->data);
	//printf("tail data: %d\n", deque_a->tail->data);
	//printf("anchor tail data: %d\n", tail_data);
	//sleep(1);
	if (node != deque_a->tail)
	{
		if (node->data > node->next->data)
		{
			sa(deque_a);
			ra(deque_a);
			//printf("go to recursive\n");
			if (deque_a->tail->data != tail_data)
			{
				recursive(deque_a, deque_b, tail_data);
			}
			rra(deque_a);
		}
		//printf("out of recursive\n");
	}
}

void	greedy_sort(t_deque *deque_a, t_deque *deque_b, int pivot_a, int pivot_b)
{
	deque_partitioning(deque_a, deque_b, pivot_a, pivot_b);
	while (deque_b->size)
	{
		pa(deque_a, deque_b);
		recursive(deque_a, deque_b, deque_a->tail->data);
	}
}

void	sort(int *array, t_deque *deque_a, t_deque *deque_b)
{
	int	size;
	int	pivot_a;
	int	pivot_b;

	size = deque_a->size;
	array_sort(array, size);
	pivot_a = array[size * 1 / 3];
	pivot_b = array[size * 2 / 3];
	if (deque_sorted(deque_a) || size == 1)
		return ;
	else if (size <= 3)
		sort_small(deque_a, size);
	else
		greedy_sort(deque_a, deque_b, pivot_a, pivot_b);
	free(array);
}
