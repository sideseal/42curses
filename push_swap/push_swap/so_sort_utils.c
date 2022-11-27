/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:55:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/28 02:31:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	get_min_data(t_deque *deque)
{
	t_list	*node;
	int	min;

	min = deque->head->data;
	node = deque->head;
	while (node)
	{
		if (min > node->data)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	get_max_data(t_deque *deque)
{
	t_list	*node;
	int	max;

	max = deque->head->data;
	node = deque->head;
	while (node)
	{
		if (max > node->data)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	check_downward(t_deque *deque, int curr)
{
	t_list	*node;
	int	index;

	node = deque->head;
	index = 0;
	while (node)
	{
		if (node == deque->head)
		{
			if (deque->tail->data < curr 
			&& curr < node->data)
				break;
		}
		if (node->next != NULL)
		{
			if (node->data < curr
			&& curr < node->next->data)
				break;
		}
		index++;
		node = node->next;
	}
	return (index);
}

int	check_upward(t_deque *deque, int curr)
{
	t_list	*node;
	int	index;

	node = deque->tail;
	index = 0;
	while (node)
	{
		if (node == deque->tail)
		{
			if (deque->head->data < curr 
			&& curr > node->data)
				break;
		}
		if (node->prev != NULL)
		{
			if (node->prev->data < curr
			&& curr < node->data)
				break;
		}
		index++;
		node = node->prev;
	}
	return (index);
}

void	array_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
