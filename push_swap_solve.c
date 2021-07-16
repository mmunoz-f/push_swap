/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:33:57 by miguel            #+#    #+#             */
/*   Updated: 2021/07/16 18:12:14 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leave_solve(t_stack *a)
{
	free_stack(a);
	exit(0);
}

void	solve_push_swap(t_stack *a, int entry_point)
{
	int		len_a;

	len_a = stack_len(a);
	if (!is_ordered(a))
	{
		if (entry_point)
			leave_solve(a);
	}
	if (len_a == 2)
		swap_op(a);
	else if (len_a == 3)
		sort_three(&a);
	else
		sort_greater(&a, len_a);
	if (entry_point)
		leave_solve(a);
}
