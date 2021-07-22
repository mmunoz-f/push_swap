/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:00:18 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 12:29:55 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*a;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	a = malloc(len + 1);
	if (!a)
		return (0);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}
