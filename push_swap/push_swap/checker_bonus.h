/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:01:14 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:40:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line_bonus.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	read_commands(char *line, t_deque *deque_a, t_deque *deque_b);

void	silent_pa(t_deque *deque_a, t_deque *deque_b);
void	silent_pb(t_deque *deque_a, t_deque *deque_b);
void	silent_rra(t_deque *deque_a);
void	silent_rrb(t_deque *deque_b);
void	silent_rrr(t_deque *deque_a, t_deque *deque_b);
void	silent_ra(t_deque *deque_a);
void	silent_rb(t_deque *deque_b);
void	silent_rr(t_deque *deque_a, t_deque *deque_b);
void	silent_sa(t_deque *deque_a);
void	silent_sb(t_deque *deque_b);
void	silent_ss(t_deque *deque_a, t_deque *deque_b);

#endif
