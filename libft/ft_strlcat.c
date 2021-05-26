/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:40:07 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 12:35:12 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	destlen;
	int	total;

	destlen = 0;
	while (dest[destlen])
		destlen++;
	i = (int)size;
	total = (int)size - destlen - 1;
	if (i - destlen > 0)
	{
		i = 0;
		while (i < total && src[i])
		{
			dest[i + destlen] = src[i];
			i++;
		}
		dest[destlen + i] = 0;
		return (destlen + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
