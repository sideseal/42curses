/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:37:23 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 13:41:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_sorted(t_deque *deque_b)
{
	t_list	*node;
	int	size;

	node = deque_b->head;
	size = deque_b->size;
	while (--size)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	deque_partition(t_deque *deque_a, t_deque *deque_b, int p_a, int p_b)
{
	int	size;

	size = deque_a->size;
	while (--size)
	{
		if (deque_a->head->data < p_a)
		{
			pb(deque_a, deque_b);
			rb(deque_b);
		}
		else if (deque_a->head->data < p_b && deque_a->head->data != p_a)
			pb(deque_a, deque_b);
		else
			ra(deque_a);
	}
	while (deque_a->size > 2)
	{
		if (deque_a->head->data != p_a && deque_a->head->data != p_b)
			pb(deque_a, deque_b);
		else
			ra(deque_a);
	}
	sort_small(deque_a, deque_b, deque_a->size);
}

t_deque	*ps_deqnew(void)
{
	t_deque	*deq;

	deq = (t_deque *)malloc(sizeof(t_deque));
	if (deq == NULL)
		exit(1);
	deq->size = 0;
	deq->head = NULL;
	deq->tail = NULL;
	return (deq);
}

void	deque_clear(t_deque *deque_a, t_deque *deque_b)
{
	if (!deque_a || !deque_b)
		return ;
	ps_lstclear(deque_a);
	ps_lstclear(deque_b);
	free(deque_a);
	free(deque_b);
}

void	deque_set(t_deque *deque_a, t_list **list, int *array, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{	
		ps_lstadd_back(list, ps_lstnew(array[i]));
		i++;
	}
	deque_a->size = argc - 1;
	deque_a->head = *list;
	deque_a->tail = ps_lstlast(*list);
}
