/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:12:59 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/24 14:03:37 by mmunoz-f         ###   ########.fr       */
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

void	sort_up_to_six(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack			*b_cmds;

	pass_half(a, b, cmds, stack_len(*a) / 2);
	read_stack(*a, "stack a\n");
	read_stack(*b, "stack b\n");
	while (*cmds)
		print_cmds(cmds);
	b_cmds = 0;
	sort_reverse_three(b, &b_cmds, 1);
	read_stack(*a, "stack a\n");
	read_stack(*b, "stack b\n");
	sort_three(a, cmds, 0);
	read_stack(*a, "stack a\n");
	read_stack(*b, "stack b\n");
	compare_cmds(cmds, &b_cmds);
	while (*b)
	{
		push_op(a, b);
		*cmds = add_back_stack(M_PA, *cmds);
	}
	while (*cmds)
		print_cmds(cmds);
	read_stack(*a, "stack a\n");
	read_stack(*b, "stack b\n");
}
