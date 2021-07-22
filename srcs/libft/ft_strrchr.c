/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:52:22 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 12:39:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*f;
	unsigned int	len;

	i = 0;
	f = 0;
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == c)
			f = (char *)&s[i];
		i++;
	}
	return (f);
}
