/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_greedy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:09:43 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/08 16:29:31 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_deque *deque_a, t_deque *deque_b, int *ia, int *ib)
{
	while (*ia > 0 && *ib > 0)
	{
		rr(deque_a, deque_b);
		*ia = *ia - 1;
		*ib = *ib - 1;
	}
	while (*ia < 0 && *ib < 0)
	{
		rrr(deque_a, deque_b);
		*ia = *ia + 1;
		*ib = *ib + 1;
	}
}

static void	rotate_deque_a(t_deque *deque_a, int index)
{
	if (index > 0)
	{
		while (index--)
			ra(deque_a);
	}
	else
	{
		index *= -1;
		while (index--)
			rra(deque_a);
	}
}

static void	rotate_deque_b(t_deque *deque_b, int index)
{
	if (index > 0)
	{
		while (index--)
			rb(deque_b);
	}
	else
	{
		index *= -1;
		while (index--)
			rrb(deque_b);
	}
}

void	greedy_sort(t_deque *deque_a, t_deque *deque_b)
{
	int	ia;
	int	ib;

	while (deque_b->size)
	{
		ia = 0;
		ib = 0;
		find_index(deque_a, deque_b, &ia, &ib);
		rotate_both(deque_a, deque_b, &ia, &ib);
		rotate_deque_a(deque_a, ia);
		rotate_deque_b(deque_b, ib);
		pa(deque_a, deque_b);
	}
}

void	sort(int *array, t_deque *deque_a, t_deque *deque_b)
{
	int	size;
	int	p_a;
	int	p_b;

	size = deque_a->size;
	array_sort(array, size);
	p_a = array[size * 1 / 3];
	p_b = array[size * 2 / 3];
	if (size <= 5)
		sort_small(deque_a, deque_b, size);
	else
	{
		deque_partition(deque_a, deque_b, p_a, p_b);
		greedy_sort(deque_a, deque_b);
		sort_finalize(deque_a);
	}
}
