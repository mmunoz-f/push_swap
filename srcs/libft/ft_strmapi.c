/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:08:21 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 12:37:27 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	a = (char *)malloc(len + 1);
	if (!a)
		return (0);
	while (i < len)
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = 0;
	return (a);
}
