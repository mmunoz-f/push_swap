/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:27:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/29 19:17:51 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static unsigned int	number_of_chunks(t_stack *a)
{
	unsigned int	len;
	unsigned int	chunks;

	len = stack_len(a);
	if (len <= 20)
		chunks = 2;
	else if (len <= 100)
		chunks = 6;
	else if (len < 500)
		chunks = 8;
	else
		chunks = 10;
	return (chunks);
}

static void	translate_cmds(t_stack *cmds)
{
	while (cmds)
	{
		if (cmds->n == M_PB)
			cmds->n = M_PA;
		else if (cmds->n == M_SA)
			cmds->n = M_SB;
		else if (cmds->n == M_RA)
			cmds->n = M_RB;
		else if (cmds->n == M_RRA)
			cmds->n = M_RRB;
		cmds = cmds->next;
	}
}

static void	solve_chunks(t_stack **a, t_stack **b, t_stack **cmds,
				t_stack **b_cmds)
{
	while (*b)
	{
		if ((*b)->next && (*b)->n < (*b)->next->n)
		{
			swap_op(*b);
			*b_cmds = add_back_stack(M_SB, *b_cmds);
		}
		if ((*b)->next)
			pass_nmax(b, a, b_cmds, 2);
		else
			pass_nmax(b, a, b_cmds, 1);
		translate_cmds(*b_cmds);
		compare_cmds(cmds, b_cmds);
		while (*cmds)
			print_cmds(cmds);
		if ((*a)->n > (*a)->next->n)
		{
			swap_op(*a);
			*cmds = add_back_stack(M_SA, *cmds);
		}
	}
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	unsigned int	chunk_len;
	t_stack			*b_cmds;

	chunk_len = stack_len(*a) / number_of_chunks(*a);
	pass_chunks(a, b, cmds, chunk_len);
	while (*cmds)
		print_cmds(cmds);
	b_cmds = 0;
	pass_nmax(b, a, &b_cmds, 3);
	translate_cmds(b_cmds);
	while (b_cmds)
		print_cmds(&b_cmds);
	sort_three(a, cmds, 0);
	solve_chunks(a, b, cmds, &b_cmds);
}
