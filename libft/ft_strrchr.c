/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:51:03 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/08 18:10:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	while (slen)
	{
		if (s[slen] == c)
			return (((char *)s) + slen);
		slen--;
	}
	return (NULL);
}
