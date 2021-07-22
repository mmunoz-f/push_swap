/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:02:48 by marvin            #+#    #+#             */
/*   Updated: 2021/01/29 12:45:32 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*a;
	char			*b;

	a = (char *)dest;
	b = (char *)src;
	i = 0;
	while (i < n && b[i] != (char)c)
	{
		a[i] = b[i];
		i++;
	}
	if (b[i] == (char)c && i < n)
	{
		a[i] = b[i];
		i++;
		return (&a[i]);
	}
	return (0);
}
