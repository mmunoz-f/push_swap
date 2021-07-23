/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:39:17 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/23 02:51:23 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	prepare_b_entrance(int n, t_stack **b, t_stack **cmds)
{

}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	int		mid;
	int		len;
	t_stack	*b_cmds;

	b_cmds = 0;
	while (is_ordered(*a, 1) && *b)
	{
		len = stack_len(*a);
		mid = get_mid_value(*a, len / 2);
		if ((*a)->n < mid)
		{
			prepare_b_entrance((*a)->n, b, &b_cmds);
			compare_cmds(cmds, &b_cmds);
			push_op(b, a);
			*cmds = add_back_stack(M_PB, *cmds);
		}
		else if ((*a)->n > (*a)->next->n)
		{
			if ((*b)->n < (*b)->next->n)
			{
				compare_cmds(cmds, &b_cmds);
				swap_op(*a);
				swap_op(*b);
				*cmds = add_back_stack(M_SS, *cmds);
			}
			else
			{
				swap_op(*a);
				*cmds = add_back_stack(M_SA, *cmds);
			}
		}
		else
		{
			rotate_op(*a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
	}
}
