/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:00:51 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/25 02:23:18 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	merge_stack(t_stack **a, t_stack **b, t_stack **cmds)
{
	unsigned int	len;
	int	steps;
	int	mid;

	len = stack_len(*b);
	while (*b && len--)
	{
		mid = get_mid_value(*b, 1);
		steps = steps_to_min(*b, mid);
		while (mid < (*b)->n && steps >= 0)
		{
			rotate_op(b);
			*cmds = add_back_stack(M_RB, *cmds);
		}
		while (mid < (*b)->n && steps < 0)
		{
			reverse_rotate_op(b);
			*cmds = add_back_stack(M_RRB, *cmds);
		}
		push_op(a, b);
		*cmds = add_back_stack(M_PA, *cmds);
	}
}

void	simple_solve(t_stack **a, t_stack **cmds, unsigned int len)
{
	t_stack	*tmp;
	t_stack	*recover;

	recover = 0;
	tmp = cpy_stack(*a, len);
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

void	simple_reverse_solve(t_stack **b, t_stack **cmds, unsigned int len)
{
	t_stack	*tmp;
	t_stack	*recover;

	recover = 0;
	tmp = cpy_stack(*b, len);
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
