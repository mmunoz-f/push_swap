/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:07:45 by miguel            #+#    #+#             */
/*   Updated: 2021/06/21 19:49:28 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
	{
		swap_op(*a);
		printf("pa\n");
		if (is_ordered(*a))
		{
			rotate_op(a);
			printf("ra\n");
		}
	}
	else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n
		&& (*a)->next->n < (*a)->next->next->n)
	{
		rotate_op(a);
		printf("ra\n");
	}
	else
	{
		reverse_rotate_op(a);
		printf("rra\n");
		if (is_ordered)
		{
			swap_op(a);
			printf("sa\n");
		}
	}
	return ;
}