/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:20:52 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/14 20:00:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] == c)
			i++;
		count++;
	}
	return (count);
}

char	*add_word(char const *s, char c, int i)
{
	size_t	j;
	size_t	len;
	char	*word;

	len = 0;
	while (s[i + len] != '\0' && s[i + len] != c)
		len++;
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

int	check_valid_word(char *word, char **words, size_t idx)
{
	size_t	i;

	if (!word)
	{
		i = 0;
		while (i <= idx)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (0);
	}
	return (1);
}

char	**make_words(char const *s, char **words, char c)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			words[idx] = add_word(s, c, i);
			if (!check_valid_word(words[idx], words, idx))
				return (NULL);
			idx++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	words[idx] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (s == NULL)
		return (NULL);
	words = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!words)
		return (NULL);
	return (make_words(s, words, c));
}
