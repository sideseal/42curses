/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/17 22:05:37 by gychoi           ###   ########.fr       */
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
	write(2, "Error\n", 6);
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
	array = get_valid_param(argc, argv);
	list = NULL;
	deque_a = ps_deqnew();
	deque_b = ps_deqnew();
	
	deque_set(deque_a, &list, array, argc);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	pb(deque_a, deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);
	
	pb(deque_a, deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);
	
	pb(deque_a, deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	rb(deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	rrb(deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	sb(deque_b);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	sa(deque_a);
	printf("deque_a iter: \n");
	iter(deque_a);
	printf("deque_b iter: \n");
	iter(deque_b);

	return (0);
}
