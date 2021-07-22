/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:50:10 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 13:41:23 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	size_t			total;

	if (!s)
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	total = ft_strlen(s);
	if ((size_t)start >= total)
		start = total;
	i = 0;
	s += start;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
