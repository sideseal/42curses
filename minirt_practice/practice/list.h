/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:45:40 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/14 21:50:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# define SP 0
# define TR 1
typedef int	obj_type;

typedef struct s_obj_list
{
	obj_type	type;
	void		*element;
	void		*next;
}	t_obj_list;

void		oadd(t_obj_list **list, t_obj_list *new);
t_obj_list	*olast(t_obj_list *list);
t_obj_list	*obj_list(obj_type type, void *element);

#endif
