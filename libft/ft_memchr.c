/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:18:30 by marvin            #+#    #+#             */
/*   Updated: 2021/01/29 17:28:34 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned int	i;

	i = 0;
	a = s;
	while (i < n)
	{
		if (a[i] == (unsigned char)c && i < n)
			return (&a[i]);
		i++;
	}
	return (0);
}
