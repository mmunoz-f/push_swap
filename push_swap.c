/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:25:44 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/05/26 19:25:44 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(int argc, char **ints)
{
	t_stack	*a;
	int		n;

	ft_bzero(a, sizeof(t_stack));
	while (argc--)
	{
		n = ft_atoi(*ints);

		ints++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = init_stack(argc - 1, argv + 1);
	ft_bzero(b, sizeof(t_stack));
	read_stack(a);
	return (0);
}
