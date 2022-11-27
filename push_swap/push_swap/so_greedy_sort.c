/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_greedy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:09:43 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/28 02:54:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
//static void	sort_type_two(t_deque *deque_a, t_deque *deque_b, int curr)
//{
//	int	d_index;
//	int	u_index;
//}
//
void	iterr(t_deque *deq)
{
	t_list	*node;

	node = deq->head;
	while (node != NULL)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("\n");
}

static void	sort_type_one(t_deque *deque_a, t_deque *deque_b, int curr)
{
	int	d_index;
	int	u_index;

	d_index = check_downward(deque_a, curr);
	u_index = check_upward(deque_a, curr);
	printf("curr: %d, d_index: %d, u_index: %d\n", curr, d_index, u_index);
	iterr(deque_a);
	if (d_index >= u_index)
	{
		while (u_index--)
			rra(deque_a);
		pa(deque_a, deque_b);
	}
	else
	{
		while (d_index--)
			ra(deque_a);
		pa(deque_a, deque_b);
	}
}

// max 값 비교한 후, tail head 인덱스 차이만큼 rra, ra 수행.
// 정렬된 상태에서만 비교해야 한다.
// 설정 후 움직인 만큼 정렬하는 함수 필요.
static void	greedy_sort(t_deque *deque_a, t_deque *deque_b)
{
	int	curr;

	while (deque_b->size)
	{
		curr = deque_b->head->data;
		//if (deque_sorted(deque_a))
		sort_type_one(deque_a, deque_b, curr);
		//else
			//sort_type_two(deque_a, deque_b, curr);
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
	if (deque_sorted(deque_a) || size == 1)
		return ;
	else if (size <= 3)
		sort_small(deque_a, size);
	else
	{
		deque_partition(deque_a, deque_b, p_a, p_b);
		greedy_sort(deque_a, deque_b);
	}
	free(array);
}
