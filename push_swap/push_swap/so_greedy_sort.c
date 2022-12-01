/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_greedy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:09:43 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/30 15:13:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	iterr(t_deque *deq)
{
	t_list	*node;

	node = deq->head;
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
void	show_deque(t_deque *a, t_deque *b)
{
	printf("\n\tA FRONT ");
	iterr(a);
	printf("REAR\n");
	printf("\tB FRONT ");
	iterr(b);
	printf("REAR\n\n");
}






int	find_best_index_mid(t_deque *deque, int data)
{
	int	d_index;
	int	u_index;

	d_index = check_downward(deque, data);
	u_index = check_upward(deque, data);
	printf("\td_index = %d, u_index = %d\n", d_index, u_index);
	if (d_index == u_index)
		d_index++;
	if (d_index < u_index)
		return (d_index);
	else
		return (u_index * -1);
}

static int	set_index(t_deque *deque_a, t_deque *deque_b, int *type)
{
	int	data;

	if (deque_b->head->data > deque_max_data(deque_a))
	{
		printf("\t[MAX]\n");
		*type = 0;
		data = deque_max_data(deque_a);
		return (find_best_index_mid(deque_a, data));
	}
	else if (deque_b->head->data < deque_min_data(deque_a))
	{
		printf("\t[MIN]\n");
		*type = 1;
		data = deque_min_data(deque_a);
		return (find_best_index_mid(deque_a, data));
	}
	else
	{
		printf("\t[MID]\n");
		*type = 2;
		data = deque_mid_data(deque_a, deque_b->head->data);
		return (find_best_index_mid(deque_a, data));
	}
}

static void	greedy_sort(t_deque *deque_a, t_deque *deque_b)
{
	int	index;
	int	type;

	while (deque_b->size)
	{
		type = -1;
		index = set_index(deque_a, deque_b, &type);
		show_deque(deque_a, deque_b);
		if (index < 0)
		{
			index *= -1;
			while (index--)
				rra(deque_a);
			if (type == 0 && index)
				ra(deque_a);
		}
		else
		{
			while (index--)
				ra(deque_a);
			if (type == 0 && index)
				rra(deque_a);
		}
		pa(deque_a, deque_b);
		show_deque(deque_a, deque_b);
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
		show_deque(deque_a, deque_b);
	}
	free(array);
}
//static void	greedy_sort(t_deque *deque_a, t_deque *deque_b)
//{
//	int	index;
//	int	type;
//	int	tmp;
//
//	while (deque_b->size)
//	{
//		type = -1;
//		index = set_index(deque_a, deque_b, &type);
//		//show_deque(deque_a, deque_b);
//		if (type == 0)
//		{
//			pa(deque_a, deque_b);
//			ra(deque_a);
//		}
//		else if (type == 1)
//			pa(deque_a, deque_b);
//		else
//		{
//			if (index < 0)
//			{
//				index *= -1;
//				//index += 1;
//				tmp = index + 1;
//				while (index--)
//					rra(deque_a);
//				pa(deque_a, deque_b);
//				//while (tmp--)
//				//	ra(deque_a);
//			}
//			else
//			{
//				//index += 1;
//				tmp = index;
//				while (index--)
//					ra(deque_a);
//				pa(deque_a, deque_b);
//				//while (tmp--)
//				//	rra(deque_a);
//			}
//		}
//	}
//}

