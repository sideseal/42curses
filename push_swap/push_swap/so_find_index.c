/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:46:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 15:42:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_best_index_max(t_deque *deque, int data)
{
	int	d_index;
	int	u_index;

	d_index = check_downward(deque, data) + 1;
	u_index = check_upward(deque, data);
	if (d_index < u_index)
		return (d_index);
	else
		return (u_index * -1);
}

int	find_best_index_min_mid(t_deque *deque, int data)
{
	int	d_index;
	int	u_index;

	d_index = check_downward(deque, data);
	u_index = check_upward(deque, data) + 1;
	if (d_index < u_index)
		return (d_index);
	else
		return (u_index * -1);
}

static int	find_deque_a_index(t_deque *deque_a, t_list *node)
{
	int	data;

	if (node->data > deque_max_data(deque_a))
	{
		data = deque_max_data(deque_a);
		return (find_best_index_max(deque_a, data));
	}
	else if (node->data < deque_min_data(deque_a))
	{
		data = deque_min_data(deque_a);
		return (find_best_index_min_mid(deque_a, data));
	}
	else
	{
		data = deque_mid_data(deque_a, node->data);
		return (find_best_index_min_mid(deque_a, data));
	}
}

static int	ps_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	find_index(t_deque *deque_a, t_deque *deque_b, int *ia, int *ib)
{
	int	i;
	int	a_idx;
	int	b_idx;
	t_list	*node;

	i = 0;
	node = deque_b->head;
	while (i < deque_b->size)
	{
		a_idx = find_deque_a_index(deque_a, node);
		b_idx = i;
		if (i >= (deque_b->size) / 2)
			b_idx = (deque_b->size - i) * -1;
		if (i == 0 || ps_abs(*ia) + ps_abs(*ib) > ps_abs(a_idx) + ps_abs(b_idx))
		{
			*ia = a_idx;
			*ib = b_idx;
		}
		node = node->next;
		i++;
	}
}
