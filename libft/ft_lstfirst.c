/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:26:49 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/31 19:36:11 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*first;

	if (!lst)
		return (0);
	first = lst;
	while (first->previous)
		first = first->previous;
	return (first);
}
