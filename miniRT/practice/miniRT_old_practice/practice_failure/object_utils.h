/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:53:42 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/27 22:02:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_UTILS
# define OBJECT_UTILS

# include "object.h"

void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);

#endif
