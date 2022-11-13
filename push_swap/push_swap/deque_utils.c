/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:37:23 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/13 23:00:39 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_deque	*ps_deqnew(void)
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

void	deque_init(t_deque **deque_a, t_deque **deque_b)
{
	*deque_a = ps_deqnew();
	*deque_b = ps_deqnew();
}
