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
		while (ft_strchr("-0123456789", **ints) && **ints)
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
	t_stack *b = 0;
	//t_stack *cmds;

	if (argc < 2)
	{
		ft_putstr_fd("Wrong input\n", 0);
		return (-1);
	}
	a = init_stack(argc - 1, argv + 1);
	if (!a)
	{
		ft_putstr_fd("Wrong input\n", 0);
		return (-1);
	}
	b = add_front_stack(2, b);
	b = add_front_stack(3, b);
	b = add_back_stack(1, b);
	b = add_front_stack(4, b);
	read_stack(a, "stack a");
	read_stack(b, "stack b");
	swap_op(b);
	read_stack(b, "swap stack b");
	push_op(&b, &a);
	read_stack(a, "pushed to b from a\nstack a");
	read_stack(b, "stack b");
	rotate_op(&b);
	read_stack(b, "rotate stack b");
	reverse_rotate_op(&b);
	read_stack(b, "reverse rotate stack b");
	//cmds = solve_push_swap(a);
	//read_stack(cmds, 0);
	return (0);
}
