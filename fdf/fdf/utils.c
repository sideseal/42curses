/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:52:46 by gychoi            #+#    #+#             */
/*   Updated: 2022/12/21 00:53:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *str)
{
	perror(str);
	exit(1);
}

void	free_fdf(t_fdf *fdf)
{
	fdf_lstclear(&(fdf->map->point));
	free(fdf->map);
	free(fdf);
}
