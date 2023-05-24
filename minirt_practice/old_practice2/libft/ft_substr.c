/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:52:19 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/15 15:02:21 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		slen;
	size_t		i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	if (slen <= start)
		substr = ft_calloc(1, sizeof(char));
	else
		substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	if (slen > start)
	{
		while (i < len && s[start + i] != '\0')
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	return (substr);
}
