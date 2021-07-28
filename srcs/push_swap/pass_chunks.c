/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:55:05 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/28 23:52:22 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	undo_moves(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack	*tmp_cmds;
	int		last;

	last = 0;
	tmp_cmds = cpy_stack(*cmds, stack_len(*cmds));
	push_op(b, a);
	while (tmp_cmds)
	{
		last = last_value(tmp_cmds);
		if (last == M_RA)
			reverse_rotate_op(a);
		else if (last == M_RRA)
			rotate_op(a);
		tmp_cmds = remove_back_stack(tmp_cmds);
	}
}

static void	reuse_actions(t_stack **a, t_stack **b, t_stack *cmds)
{
	undo_moves(a, b, cmds); //now it should redo all cmds, substituing reusable moves
	while (cmds)
	{
		while (cmds && cmds->n != M_RA)
			cmds = cmds->next;
		if (cmds && (*b)->next && (*b)->n < (*b)->next->n)
		{
			rotate_op(b);
			cmds->n = M_RR;
		}
		if (cmds)
			cmds = cmds->next;
	}
}

void	pass_chunks(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	t_stack			*cmds;
	unsigned int	len;

	while (*a)
	{
		if (*b)
			reuse_actions(a, b, cmds);
		while (*cmds)
			print_cmds(cmds);
		len = stack_len(*a);
		if (len > chunk_len)
			len = chunk_len;
		pass_nmin(a, b, cmds, len);
	}
}
