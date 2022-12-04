/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:48:17 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/04 22:46:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	silent_ss(t_deque *deque_a, t_deque *deque_b)
{
	silent_sa(deque_a);
	silent_sb(deque_b);
}

static void	silent_rrr(t_deque *deque_a, t_deque *deque_b)
{
	silent_rra(deque_a);
	silent_rrb(deque_b);
}

static void	silent_rr(t_deque *deque_a, t_deque *deque_b)
{
	silent_ra(deque_a);
	silent_rb(deque_b);
}

static void	run_command(char *line, t_deque *deque_a, t_deque *deque_b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		silent_sa(deque_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		silent_sb(deque_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		silent_ss(deque_a, deque_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		silent_pa(deque_a, deque_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		silent_pb(deque_a, deque_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		silent_rra(deque_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		silent_rrb(deque_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		silent_rrr(deque_a, deque_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		silent_ra(deque_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		silent_rb(deque_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		silent_rr(deque_a, deque_b);
	else
		ps_error();
}

void	read_commands(char *line, t_deque *deque_a, t_deque *deque_b)
{
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, "\n", 1) == 0)
		{
			free(line);
			break ;
		}
		run_command(line, deque_a, deque_b);
		free(line);
	}
}
