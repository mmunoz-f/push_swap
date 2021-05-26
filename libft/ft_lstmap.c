/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:26:22 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 12:23:50 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*lstcpy;

	lstcpy = 0;
	while (lst)
	{
		newlst = ft_lstnew((*f)(lst->content));
		if (!newlst)
		{
			ft_lstclear(&lstcpy, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&lstcpy, newlst);
	}
	return (lstcpy);
}
