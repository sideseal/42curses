/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:17:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 20:56:19 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_element_count(char **tokens)
{
	size_t	count;

	count = count_tokens(tokens);
	if (count != 3)
		return (FALSE);
	return (TRUE);
}

t_bool	check_element_csv(char *csv, int type)
{
	size_t	token_count;
	t_bool	ret_val;
	char	**csv_tokens;

	ret_val = FALSE;
	csv_tokens = ft_split(csv, ',');
	token_count = count_tokens(csv_tokens);
	if (count_char(csv, ',') == 2 && token_count == 3)
	{
		ret_val = TRUE;
		while (token_count--)
		{
			if (type == INT)
				if (is_int(csv_tokens[token_count]) == FALSE)
					ret_val = FALSE;
			if (type == FLOAT)
				if (is_float(csv_tokens[token_count]) == FALSE)
					ret_val = FALSE;
		}
	}
	free_tokens(csv_tokens);
	return (ret_val);
}

t_bool	check_element_value(char *elem, int type)
{
	if (type == INT)
		if (is_int(elem) == FALSE)
			return (FALSE);
	if (type == FLOAT)
		if (is_float(elem) == FALSE)
			return (FALSE);
	return (TRUE);
}

t_bool	check_file_ext(char	*file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (FALSE);
	if (file[len - 3] != '.' || file[len - 2] != 'r' || file[len - 1] != 't')
		return (FALSE);
	return (TRUE);
}
