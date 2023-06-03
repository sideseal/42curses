/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:17:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/03 23:24:59 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_elem_fmt(char **tokens)
{
	printf("%p\n", tokens);
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