/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:59:54 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 12:09:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	t;
	char	*a;

	i = 0;
	a = (char *)malloc(count * size);
	if (!a)
		return (0);
	t = count * size;
	while (i < t)
	{
		a[i] = 0;
		i++;
	}
	return ((void *)a);
}
