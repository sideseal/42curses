/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:55:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/29 11:29:32 by gychoi           ###   ########.fr       */
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

void	sort_small(t_deque *deque_a, int size)
{
	if (size == 1)
		return ;
	else if (size == 2 && !deque_sorted(deque_a))
		sa(deque_a);
	else if (size == 3 && !deque_sorted(deque_a))
		sort_three(deque_a);
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
