/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:55:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 13:39:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_deque *deque_a)
{
	if (deque_a->head->data > deque_a->head->next->data
		&& deque_a->head->data > deque_a->tail->data)
		ra(deque_a);
	else if (deque_a->head->next->data > deque_a->head->data
		&& deque_a->head->next->data > deque_a->tail->data)
		rra(deque_a);
	if (deque_a->head->data > deque_a->head->next->data)
		sa(deque_a);
}

void	sort_small(t_deque *deque_a, t_deque *deque_b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sa(deque_a);
	else if (size == 3)
		sort_three(deque_a);
	else
	{
		while (deque_a->size > 3)
			pb(deque_a, deque_b);
		sort_three(deque_a);
		greedy_sort(deque_a, deque_b);
		sort_finalize(deque_a);
	}
}

void	sort_finalize(t_deque *deque_a)
{
	int	min;
	int	index;

	min = deque_min_data(deque_a);
	index = find_best_index_min_mid(deque_a, min);
	if (index < 0)
	{
		index *= -1;
		while (index--)
			rra(deque_a);
	}
	else
	{
		while (index--)
			ra(deque_a);
	}
}

void	array_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
