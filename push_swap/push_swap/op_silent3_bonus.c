/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_silent3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:01:18 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:02:16 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	silent_ss(t_deque *deque_a, t_deque *deque_b)
{
	silent_sa(deque_a);
	silent_sb(deque_b);
}

void	silent_rrr(t_deque *deque_a, t_deque *deque_b)
{
	silent_rra(deque_a);
	silent_rrb(deque_b);
}

void	silent_rr(t_deque *deque_a, t_deque *deque_b)
{
	silent_ra(deque_a);
	silent_rb(deque_b);
}
