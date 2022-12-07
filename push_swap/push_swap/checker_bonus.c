/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:24:51 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/07 20:57:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((((unsigned char *)s1)[i] < ((unsigned char *)s2)[i]) || \
			(((unsigned char *)s1)[i] > ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*array;
	char	*line;
	t_list	*list;
	t_deque	*deque_a;
	t_deque	*deque_b;

	if (argc < 2)
		return (0);
	list = NULL;
	deque_a = ps_deqnew();
	deque_b = ps_deqnew();
	array = get_valid_param(argc, argv);
	deque_set(deque_a, &list, array, argc);
	line = NULL;
	read_commands(line, deque_a, deque_b);
	if (deque_sorted(deque_a) && deque_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	deque_clear(deque_a, deque_b);
	free(array);
	return (0);
}
