/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:17:18 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 23:14:15 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_file_ext(char	*file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (FALSE);
	if (file[len - 3] != '.' || file[len - 2] != 'r' || file[len - 1] != 't')
		return (FALSE);
	return (TRUE);
}
