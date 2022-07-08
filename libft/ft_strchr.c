/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:30:53 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/08 18:08:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	size_t	slen;
	size_t	i;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	i = 0;
	while (i <= slen)
	{
		if (s[i] == c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
