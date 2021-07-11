/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:33:57 by miguel            #+#    #+#             */
/*   Updated: 2021/07/11 11:14:42 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_stack(t_stack *a, t_stack *b)
{
	while (b)
	{
		push_op(&b, &a);
		printf("pa\n");
	}
}

void	solve_push_swap(t_stack *a)
{
	t_stack	*b;
	int		len_a;

	b = 0;
	while (is_ordered(a) || is_ordered(b))
	{
		len_a = stack_len(a);
		if (len_a == 2 && a->n > a->next->n)
		{
			swap_op(a);
			printf("sa\n");
		}
		else if (len_a == 3)
			sort_three(a);
		else
			greater_stack_solve(a);
	}
	merge_stack(a, b);
	free_stack(a);
}
