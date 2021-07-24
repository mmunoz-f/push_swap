/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:00:58 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/24 17:01:35 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_reverse_stack(t_stack **a, t_stack **b, t_stack **cmds, int min)
{
	while ()
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack	*tmp;
	int		min;

	while (is_ordered(*a, 1) || *b)
	{
		get_max_min(*a, 0, &min);
		sort_reverse_stack(a, b, cmds, min);
		if ((*a)->n == min)
		{
			push_op(&tmp, a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		else if ((*a)->n > (*a)->next->n)
		{
			swap_op(*a);
			*cmds = add_back_stack(M_SA, *cmds);
		}
		else
		{
			push_op(b, a);
			*cmds = add_back_stack(M_PB, *cmds);
		}
	}
}
