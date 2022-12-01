/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:46:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/30 12:46:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_index(t_deque *deque, int data)
{
	int	d_index;
	int	u_index;

	d_index = check_downward(deque, data);
	u_index = check_upward(deque, data);
	if (d_index <= u_index)
		return (d_index);
	else
		return (u_index * -1);
}
