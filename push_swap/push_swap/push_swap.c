/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/14 01:55:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "stdio.h"

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
	printf("%d\n", deque_a->head->data);
	printf("size: %d\n", deque_a->size);
	pb(deque_a, deque_b);
	printf("%d, %d\n", deque_a->head->data, deque_b->head->data);
	printf("size: %d, %d\n", deque_a->size, deque_b->size);
	return (0);
}
