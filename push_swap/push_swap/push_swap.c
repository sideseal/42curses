/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/25 23:14:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "stdio.h"
void	iter(t_deque *deq)
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

void	ps_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	*array;
	t_list	*list;
	t_deque	*deque_a;
	t_deque	*deque_b;

	if (argc < 2)
		return (0);
	list = NULL;
	deque_a = ps_deqnew();
	deque_b = ps_deqnew();
	array = get_valid_param(argc, argv);
	deque_set(deque_a, &list, array, argc);
	sort(array, deque_a, deque_b);
	return (0);
}
