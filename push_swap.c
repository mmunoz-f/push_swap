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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cmds;

	if (argc < 2)
		error_exit("Error\nBad number of arguments\n", 1);
	a = 0;
	charge_arguments(argc - 1, argv + 1, &a);
	b = 0;
	cmds = 0;
	if (!a)
		error_exit("Error\nNot valid arguments\n", 1);
	solve_push_swap(&a, &b, &cmds);
	return (0);
}
