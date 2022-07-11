/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:39:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/11 16:19:46 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char const *set, char ch)
{
	size_t	k;

	k = 0;
	while (set[k] != '\0')
	{
		if (set[k] == ch)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	strlen;
	size_t	i;
	size_t	j;
	char	*string;

	if (s1 == NULL || set == NULL)
		return (NULL);
	strlen = ft_strlen(s1);
	string = malloc(sizeof(char) * strlen + 1);
	if (!string)
		return (NULL);
	i = 0;
	if (check_set(set, s1[0]))
		i++;
	if (check_set(set, s1[strlen - 1]))
		strlen--;
	j = 0;
	while (i < strlen)
		string[j++] = s1[i++];
	string[j] = '\0';
	return (string);
}
