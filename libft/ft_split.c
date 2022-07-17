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

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count ++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*add_word(char const *s, char c, int i)
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

static char	**free_memory(char **words, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		free(words[i]);
		words[i] = NULL;
		i++;
	}
	free(words);
	return (NULL);
}

static char	**make_words(char const *s, char **words, char c)
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
			if (!words[idx])
				return (free_memory(words, idx));
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
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = word_count(s, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (make_words(s, words, c));
}
