/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:10:46 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/14 01:52:26 by gychoi           ###   ########.fr       */
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
	int	idx;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_deque
{
	int	size;
	struct s_list	*head;
	struct s_list	*tail;
}	t_deque;

void	deque_set(t_deque *deque_a, t_list **list, int *array, int argc);
t_deque	*ps_deqnew(void);

void	ps_lstadd_back(t_list **lst, t_list *new);
t_list	*ps_lstnew(int value);
t_list	*ps_lstlast(t_list *lst);

void	pb(t_deque *deque_a, t_deque *deque_b);

#endif
