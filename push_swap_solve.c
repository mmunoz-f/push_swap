/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:33:57 by miguel            #+#    #+#             */
/*   Updated: 2021/06/21 19:07:31 by miguel           ###   ########.fr       */
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
		if (len_a == 3)
			sort_three(a);
	}
	merge_stack(a, b);
	free_stack(a);
}
