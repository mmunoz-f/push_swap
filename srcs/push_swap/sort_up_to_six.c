/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:12:59 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/29 19:03:24 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	join_cmds(t_stack **a, t_stack **b)
{
	if ((*a)->n == M_SA && (*b)->n == M_SB)
	{
		(*a)->n = M_SS;
		*b = remove_front_stack(*b);
	}
	else if ((*a)->n == M_RA && (*b)->n == M_RB)
	{
		(*a)->n = M_RR;
		*b = remove_front_stack(*b);
	}
	else if ((*a)->n == M_RRA && (*b)->n == M_RRB)
	{
		(*a)->n = M_RRR;
		*b = remove_front_stack(*b);
	}
}

void	compare_cmds(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && *b)
	{
		join_cmds(&tmp, b);
		tmp = tmp->next;
	}
	while (*b)
	{
		*a = add_back_stack((*b)->n, *a);
		*b = remove_front_stack(*b);
	}
}

static void	solve_stack(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack	*b_cmds;

	b_cmds = 0;
	if (is_ordered(*b, 0))
	{
		if (stack_len(*b) == 2)
		{
			swap_op(*b);
			b_cmds = add_back_stack(M_SB, b_cmds);
		}
		sort_reverse_three(b, &b_cmds, 1);
	}
	if (is_ordered(*a, 1))
	{
		if (stack_len(*a) == 2)
		{
			swap_op(*a);
			*cmds = add_back_stack(M_SA, *cmds);
		}
		sort_three(a, cmds, 0);
	}
	compare_cmds(cmds, &b_cmds);
}

void	sort_up_to_six(t_stack **a, t_stack **b, t_stack **cmds)
{
	pass_nmin(a, b, cmds, 3);
	while (*cmds)
		print_cmds(cmds);
	solve_stack(a, b, cmds);
	while (*b)
	{
		push_op(a, b);
		*cmds = add_back_stack(M_PA, *cmds);
	}
	while (*cmds)
		print_cmds(cmds);
}
