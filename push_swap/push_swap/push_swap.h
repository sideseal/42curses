/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:10:46 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/30 00:15:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

void	ps_error(void);
int	*get_valid_param(int argc, char **argv);

typedef struct	s_list
{
	int	data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_deque
{
	int	size;
	struct s_list	*head;
	struct s_list	*tail;
}	t_deque;

t_deque	*ps_deqnew(void);
int	deque_sorted(t_deque *deque_b);
void	deque_set(t_deque *deque_a, t_list **list, int *array, int argc);
void	deque_partition(t_deque *deque_a, t_deque *deque_b, int p_a, int p_b);

void	ps_lstadd_back(t_list **lst, t_list *new);
t_list	*ps_lstnew(int value);
t_list	*ps_lstlast(t_list *lst);

void	pb(t_deque *deque_a, t_deque *deque_b);
void	pa(t_deque *deque_a, t_deque *deque_b);

void	ra(t_deque *deque_a);
void	rb(t_deque *deque_b);
void	rr(t_deque *deque_a, t_deque *deque_b);

void	rra(t_deque *deque_a);
void	rrb(t_deque *deque_b);
void	rrr(t_deque *deque_a, t_deque *deque_b);

void	sa(t_deque *deque_a);
void	sb(t_deque *deque_b);
void	ss(t_deque *deque_a, t_deque *deque_b);

void	sort(int *array, t_deque *deque_a, t_deque *deque_b);
void	sort_small(t_deque *deque_a, int size);
void	array_sort(int *array, int size);

int	deque_min_data(t_deque *deque);
int	deque_max_data(t_deque *deque);
int	deque_mid_data(t_deque *deque, int data);
int	check_upward(t_deque *deque, int data);
int	check_downward(t_deque *deque, int data);

int	find_best_index(t_deque *deque, int data);
#endif
