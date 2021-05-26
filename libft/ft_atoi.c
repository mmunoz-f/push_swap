/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:08:44 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 13:44:14 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	nbr;
	int				n;

	i = 0;
	nbr = 0;
	n = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] < 14 && nptr[i] > 8)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = 1;
		i++;
	}
	while (nptr[i] < 58 && nptr[i] > 47)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (n == 0)
		return ((int)nbr);
	return (-(int)nbr);
}
