/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:55:34 by marvin            #+#    #+#             */
/*   Updated: 2021/02/01 17:30:12 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	total;

	i = 0;
	if (!(ft_strlen(little)))
		return (big);
	while (big[i] && i < len)
	{
		total = 0;
		while (big[i + total] == little[total] && i + total < len)
		{
			total++;
			if (little[total] == 0)
				return (&big[i]);
		}
		i++;
	}
	return (0);
}
