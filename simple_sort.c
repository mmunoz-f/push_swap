/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:00:51 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/20 23:48:34 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_solve(t_stack **a, t_stack **cmds)
{
	while (is_ordered(*a, 1))
	{
		if ((*a)->n > (*a)->next->n)
		{
			swap_op(*a);
			*cmds = add_back_stack(M_SA, *cmds);
		}
		else
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		reverse_rotate_op(a);
		*cmds = add_back_stack(M_RRA, *cmds);
	}
}

void	simple_reverse_solve(t_stack **b, t_stack **cmds)
{
	while (is_ordered(*b, 0))
	{
		if ((*b)->n < (*b)->next->n)
		{
			swap_op(*b);
			*cmds = add_back_stack(M_SB, *cmds);
		}
		else
		{
			rotate_op(b);
			*cmds = add_back_stack(M_RB, *cmds);
		}
		reverse_rotate_op(b);
		*cmds = add_back_stack(M_RRB, *cmds);
	}
}
