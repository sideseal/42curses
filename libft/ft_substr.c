/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:52:19 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/09 17:01:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		slen;
	int		i;

	slen = 0;
	i = 0;
	while (s[slen] != '\0')
		slen++;
	if ((unsigned int)slen < start)
		sub = malloc(sizeof(char));
	else
	{
		sub = malloc(sizeof(char) * len + 1);
		if (!sub)
			return (NULL);
		while (start < len && s[start] != '\0')
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
