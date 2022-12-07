/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:52:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*array;
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
	if (!deque_sorted(deque_a))
		sort(array, deque_a, deque_b);
	deque_clear(deque_a, deque_b);
	free(array);
	return (0);
}
