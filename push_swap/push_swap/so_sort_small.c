/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:09:20 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/20 22:13:27 by gychoi           ###   ########.fr       */
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
	else if (size == 2)
		sa(deque_a);
	else if (size == 3)
		sort_three(deque_a);
}
