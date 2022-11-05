/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:10:46 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/05 23:09:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

void	ps_error(void);
void	check_param(int *array, int argc, char **argv);

typedef struct	s_node
{
	int	data;
	int	idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	int	size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_deque;

#endif
