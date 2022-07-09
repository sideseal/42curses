/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:11:41 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/09 17:15:30 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		len1;
	int		len2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	string = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!string)
		return (NULL);
	i = -1;
	while (++i < len1)
		string[i] = s1[i];
	i = 0;
	while (i < len2)
		string[len1++] = s2[i++];
	string[len1 + len2] = '\0';
	return (string);
}
