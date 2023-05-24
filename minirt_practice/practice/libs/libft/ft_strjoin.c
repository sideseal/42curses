/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/11 15:28:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	pflen;
	size_t	sflen;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pflen = ft_strlen(s1);
	sflen = ft_strlen(s2);
	string = malloc(sizeof(char) * (pflen + sflen) + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, pflen + 1);
	ft_strlcpy(string + pflen, s2, sflen + 1);
	return (string);
}
