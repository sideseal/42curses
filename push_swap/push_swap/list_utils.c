/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:04:05 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/02 22:01:08 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ps_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		exit(1);
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ps_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = ps_lstlast(*lst);
	curr->next = new;
	new->prev = curr;
	new->next = NULL;
}

void	ps_lstclear(t_deque *deque)
{
	t_list	*next;
	t_list	*node;

	node = deque->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(node);
}
