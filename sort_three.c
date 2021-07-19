/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:07:45 by miguel            #+#    #+#             */
/*   Updated: 2021/07/19 23:20:37 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_cmds(t_stack **cmds, int op, int stack)
{
	if (stack)
	{
		if (op == M_RA)
			op = M_RB;
		else if (op == M_RRA)
			op = M_RRB;
		else if (op == M_SA)
			op = M_SB;
	}
	*cmds = add_back_stack(op, *cmds);
}

static void	third_case(t_stack **a, t_stack **cmds, int stack)
{
	reverse_rotate_op(a);
	add_cmds(cmds, M_RRA, stack);
	if (is_ordered(*a, 1))
	{
		swap_op(*a);
		add_cmds(cmds, M_SA, stack);
	}
}

void	sort_three(t_stack **a, t_stack **cmds, int stack)
{
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
	{
		swap_op(*a);
		add_cmds(cmds, M_SA, stack);
		if (is_ordered(*a, 1))
		{
			rotate_op(a);
			add_cmds(cmds, M_RA, stack);
		}
	}
	else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n
		&& (*a)->next->n < (*a)->next->next->n)
	{
		rotate_op(a);
		add_cmds(cmds, M_RA, stack);
	}
	else
		third_case(a, cmds, stack);
}
