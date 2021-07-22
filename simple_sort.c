/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:00:51 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/22 20:51:53 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_three_biggest(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack	*tmp;
	int		i;
	int		mid;
	int		recover;

	tmp = cpy_stack(*b, 6);
	i = 3;
	recover = 0;
	mid = get_mid_value(tmp, 3);
	while (i || recover)
	{
		if (!i && recover)
		{
			reverse_rotate_op(b);
			*cmds = add_back_stack(M_RRB, *cmds);
			recover--;
			continue ;
		}
		if ((*b)->n > mid)
		{
			push_op(a, b);
			*cmds = add_back_stack(M_PA, *cmds);
			i--;
		}
		else
		{
			rotate_op(b);
			*cmds = add_back_stack(M_RB, *cmds);
			recover++;
		}
	}
	free_stack(tmp);
}

void	simple_solve(t_stack **a, t_stack **cmds)
{
	t_stack	*tmp;
	t_stack	*recover;

	recover = 0;
	tmp = cpy_stack(*a, 3);
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
	tmp = cpy_stack(*b, 3);
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
