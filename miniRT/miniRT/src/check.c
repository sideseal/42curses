/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:17:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/05 20:28:11 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_element_attr(char *elem, int type_p)
{
	int		error;

	error = FALSE;
	if (type_p == COORD || type_p == DIMEN)
		if (INT_MAX < rt_atof(elem, &error) || \
			rt_atof(elem, &error) < INT_MIN || error == TRUE)
			return (FALSE);
	if (type_p == FOV)
		if (180 < ft_atoi(elem) || ft_atoi(elem) < 0)
			return (FALSE);
	if (type_p == LIGHT)
		if (1.0 < rt_atof(elem, &error) || \
			rt_atof(elem, &error) < 0.0 || error == TRUE)
			return (FALSE);
	if (type_p == NORM)
		if (1.0 < rt_atof(elem, &error) || \
			rt_atof(elem, &error) < -1.0 || error == TRUE)
			return (FALSE);
	if (type_p == RGB)
		if (255 < ft_atoi(elem) || ft_atoi(elem) < 0)
			return (FALSE);
	return (TRUE);
}

t_bool	check_element_count(char **tokens, size_t size)
{
	size_t	count;

	count = count_tokens(tokens);
	if (count != size)
		return (FALSE);
	return (TRUE);
}

t_bool	check_element_csv(char *csv, int type_p, int type_d)
{
	size_t	token_count;
	t_bool	ret_val;
	char	**csv_tokens;

	ret_val = FALSE;
	csv_tokens = ft_split(csv, ',');
	token_count = count_tokens(csv_tokens);
	if (count_char(csv, ',') == 2 && count_tokens(csv_tokens) == 3)
	{
		ret_val = TRUE;
		while (token_count--)
		{
			if (type_d == INT)
				if (is_int_fmt(csv_tokens[token_count]) == FALSE)
					ret_val = FALSE;
			if (type_d == FLOAT)
				if (is_float_fmt(csv_tokens[token_count]) == FALSE)
					ret_val = FALSE;
			if (check_element_attr(csv_tokens[token_count], type_p) == FALSE)
				ret_val = FALSE;
		}
	}
	free_tokens(csv_tokens);
	return (ret_val);
}

t_bool	check_element_value(char *elem, int type_p, int type_d)
{
	// check property
	if (type_d == INT)
		if (is_int_fmt(elem) == FALSE)
			return (FALSE);
	if (type_d == FLOAT)
		if (is_float_fmt(elem) == FALSE)
			return (FALSE);
	if (check_element_attr(elem, type_p) == FALSE)
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
	if (file[len - 4] == '/')
		return (FALSE);
	return (TRUE);
}
