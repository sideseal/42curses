/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:36 by gychoi            #+#    #+#             */
/*   Updated: 2022/07/16 14:24:48 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nnew;
	t_list	*nlst;

	if (!lst || !f)
		return (NULL);
	nlst = NULL;
	while (lst != NULL)
	{
		nnew = ft_lstnew(f(lst->content));
		if (!nnew)
		{
			ft_lstclear(&nlst, del);
			nlst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&nlst, nnew);
		lst = lst->next;
	}
	return (nlst);
}
