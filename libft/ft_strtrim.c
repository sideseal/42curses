/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:39:22 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/15 17:42:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char const *set, char ch)
{
	size_t	k;

	k = 0;
	while (set[k] != '\0')
	{
		if (set[k] == (unsigned char)ch)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	i;
	size_t	j;
	char	*string;

	if (s1 == NULL || set == NULL)
		return (NULL);
	slen = ft_strlen(s1);
	i = 0;
	while (check_set(set, s1[i]))
		i++;
	while (check_set(set, s1[slen - 1]))
		slen--;
	if (i > slen)
		string = malloc(sizeof(char));
	else
		string = malloc(sizeof(char) * slen - i + 1);
	if (!string)
		return (NULL);
	j = 0;
	while (i < slen)
		string[j++] = s1[i++];
	string[j] = '\0';
	return (string);
}
