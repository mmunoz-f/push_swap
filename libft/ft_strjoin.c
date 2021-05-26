/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:03:02 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 12:31:42 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	unsigned int	i;
	char			*f;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	f = malloc(len1 + len2 + 1);
	if (!f)
		return (0);
	i = 0;
	len2 = len1 + len2;
	while (i < len2)
	{
		if (i < len1)
			f[i] = s1[i];
		else
			f[i] = s2[i - len1];
		i++;
	}
	f[i] = 0;
	return (f);
}
