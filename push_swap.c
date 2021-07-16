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

static t_stack	*init_stack(int argc, char **ints)
{
	t_stack	*a;
	int		n;

	a = 0;
	while (argc--)
	{
		if (!(ft_strchr("-0123456789", **ints)))
			return (0);
		n = ft_atoi(*ints);
		if (**ints == '-')
			(*ints)++;
		while (ft_strchr("0123456789", **ints) && **ints)
			(*ints)++;
		if (**ints)
			return (0);
		a = add_back_stack(n, a);
		ints++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 0);
		return (1);
	}
	a = init_stack(argc - 1, argv + 1);
	if (!a)
	{
		ft_putstr_fd("Error\n", 0);
		return (1);
	}
	solve_push_swap(a, 1);
	return (0);
}
