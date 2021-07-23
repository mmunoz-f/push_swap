/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:00:51 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/23 00:34:44 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	simple_solve(t_stack **a, t_stack **cmds)
{
	t_stack	*tmp;
	t_stack	*recover;

	recover = 0;
	tmp = cpy_stack(*a, stack_len(*a));
	while (is_ordered(tmp, 1) || recover)
	{
		if (!is_ordered(tmp, 1) && recover)
		{
			reverse_rotate_op(a);
			push_op(&tmp, &recover);
			*cmds = add_back_stack(M_RRA, *cmds);
			continue ;
		}
		if ((*a)->n > (*a)->next->n)
		{
			swap_op(*a);
			swap_op(tmp);
			*cmds = add_back_stack(M_SA, *cmds);
		}
		else
		{
			rotate_op(a);
			push_op(&recover, &tmp);
			*cmds = add_back_stack(M_RA, *cmds);
		}
	}
	free_stack(tmp);
}

void	simple_reverse_solve(t_stack **b, t_stack **cmds)
{
	t_stack	*tmp;
	t_stack	*recover;

	recover = 0;
	tmp = cpy_stack(*b, stack_len(*b));
	while (is_ordered(tmp, 0) || recover)
	{
		if (!is_ordered(tmp, 0) && recover)
		{
			reverse_rotate_op(b);
			push_op(&tmp, &recover);
			*cmds = add_back_stack(M_RRB, *cmds);
			continue ;
		}
		if ((*b)->n < (*b)->next->n)
		{
			swap_op(*b);
			swap_op(tmp);
			*cmds = add_back_stack(M_SB, *cmds);
		}
		else
		{
			rotate_op(b);
			push_op(&recover, &tmp);
			*cmds = add_back_stack(M_RB, *cmds);
		}
	}
	free_stack(tmp);
}
