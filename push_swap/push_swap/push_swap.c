/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/11/05 23:09:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "stdio.h"

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	array[argc - 1];

	if (argc < 2)
		return (0);
	check_param(array, argc, argv);
	for (int i = 0; i < argc - 1; i++)
		printf("%d ", array[i]);
	return (0);
}
