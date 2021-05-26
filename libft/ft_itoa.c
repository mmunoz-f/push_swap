/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:48:12 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 13:44:46 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nlength(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*a;

	size = ft_nlength(n);
	a = (char *)malloc(size + 1);
	if (!a)
		return (0);
	if (n < 0)
	{
		a[0] = '-';
		nbr = -(unsigned int)n;
	}
	else
		nbr = (unsigned int)n;
	a[size] = 0;
	while (nbr || !(n--))
	{
		a[--size] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (a);
}
