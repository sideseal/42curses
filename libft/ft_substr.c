/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:52:19 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/14 20:28:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		slen;
	size_t		sidx;
	size_t		i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	sidx = start;
	while (sidx < (len + (size_t)start) \
		&& s[sidx] != '\0' && slen >= start)
	{
		substr[i] = s[sidx];
		i++;
		sidx++;
	}
	substr[i] = '\0';
	return (substr);
}
