/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:07:45 by miguel            #+#    #+#             */
/*   Updated: 2021/07/22 23:05:00 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

static void	third_reverse_case(t_stack **a, t_stack **cmds, int stack)
{
	reverse_rotate_op(a);
	add_cmds(cmds, M_RRA, stack);
	if (is_ordered(*a, 0))
	{
		swap_op(*a);
		add_cmds(cmds, M_SA, stack);
	}
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

void	sort_reverse_three(t_stack **a, t_stack **cmds, int stack)
{
	if ((*a)->n < (*a)->next->n && (((*a)->next->n < (*a)->next->next->n
			&& (*a)->n < (*a)->next->next->n)
		|| ((*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n)))
	{
		swap_op(*a);
		add_cmds(cmds, M_SA, stack);
		if (is_ordered(*a, 0))
		{
			reverse_rotate_op(a);
			add_cmds(cmds, M_RRA, stack);
		}
	}
	else if ((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n
		&& (*a)->next->n > (*a)->next->next->n)
	{
		rotate_op(a);
		add_cmds(cmds, M_RA, stack);
	}
	else
		third_reverse_case(a, cmds, stack);
}

void	sort_three(t_stack **a, t_stack **cmds, int stack)
{
	if ((*a)->n > (*a)->next->n && (((*a)->next->n < (*a)->next->next->n
				&& (*a)->n < (*a)->next->next->n)
			|| ((*a)->next->n > (*a)->next->next->n
				&& (*a)->n > (*a)->next->next->n)))
	{
		swap_op(*a);
		add_cmds(cmds, M_SA, stack);
		if (is_ordered(*a, 1))
		{
			reverse_rotate_op(a);
			add_cmds(cmds, M_RRA, stack);
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
