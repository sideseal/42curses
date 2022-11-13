/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/13 23:28:11 by gychoi           ###   ########.fr       */
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
	deque_a = NULL;
	deque_b = NULL;
	list = NULL;
	array = get_valid_param(argc, argv);
	deque_init(&deque_a, &deque_b);
	deque_set(deque_a, &list, array, argc);
	printf("%d, %d, %d\n", deque_a->tail->data, deque_a->tail->prev->data, deque_a->tail->prev->prev->data);
	return (0);
}
