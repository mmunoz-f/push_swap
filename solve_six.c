/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:12:33 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 18:42:47 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	compare_cmds(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && *b)
	{
		join_cmds(&tmp, b);
		tmp = tmp->next;
	}
	while (*b)
		*a = add_back_stack((*b)->n, *a);
}

static void	solve_stack(t_stack **a, t_stack **cmds)
{
	unsigned int	len;

	len = stack_len(*a);
	if (len == 2 && (*a)->n > (*a)->next->n)
	{
		swap_op(*a);
		*cmds = add_back_stack(M_SA, *cmds);
	}
	else if (len == 3)
		sort_three(a, cmds, 0);
	else
		simple_solve(a, cmds);
}

static void	solve_reverse_stack(t_stack **a, t_stack **cmds)
{
	unsigned int	len;

	len = stack_len(*a);
	if (len == 2 && (*a)->n < (*a)->next->n)
	{
		swap_op(*a);
		*cmds = add_back_stack(M_SB, *cmds);
	}
	else if (len == 3)
		sort_reverse_three(a, cmds, 1);
	else
		simple_reverse_solve(a, cmds);
}

void	solve_six(t_stack **a, t_stack **a_cmds)
{
	t_stack			*b_cmds;

	b_cmds = 0;
	if (*a_cmds)
	{
		if (is_ordered(*a, 0))
			solve_reverse_stack(a, &b_cmds);
		compare_cmds(a_cmds, &b_cmds);
	}
	else
	{
		if (is_ordered(*a, 1))
			solve_stack(a, a_cmds);
	}
}
