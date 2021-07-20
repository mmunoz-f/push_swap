/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:33:57 by miguel            #+#    #+#             */
/*   Updated: 2021/07/20 22:10:49 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmds(t_stack **cmds)
{
	if ((*cmds)->n == M_SA)
		write(STDOUT_FILENO, "sa\n", 3);
	else if ((*cmds)->n == M_SB)
		write(STDOUT_FILENO, "sb\n", 3);
	else if ((*cmds)->n == M_SS)
		write(STDOUT_FILENO, "ss\n", 3);
	else if ((*cmds)->n == M_PA)
		write(STDOUT_FILENO, "pa\n", 3);
	else if ((*cmds)->n == M_PB)
		write(STDOUT_FILENO, "pb\n", 3);
	else if ((*cmds)->n == M_RA)
		write(STDOUT_FILENO, "ra\n", 3);
	else if ((*cmds)->n == M_RB)
		write(STDOUT_FILENO, "rb\n", 3);
	else if ((*cmds)->n == M_RR)
		write(STDOUT_FILENO, "rr\n", 3);
	else if ((*cmds)->n == M_RRA)
		write(STDOUT_FILENO, "rra\n", 4);
	else if ((*cmds)->n == M_RRB)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if ((*cmds)->n == M_RRR)
		write(STDOUT_FILENO, "rrr\n", 4);
	*cmds = remove_front_stack(*cmds);
}

void	leave_solve(t_stack *a, t_stack *cmds)
{
	while (cmds)
		print_cmds(&cmds);
	free_stack(a);
	exit(0);
}

void	solve_push_swap(t_stack **a, t_stack **b, t_stack **cmds)
{
	int		len_a;

	len_a = stack_len(*a);
	if (!is_ordered(*a, 1))
		leave_solve(*a, *cmds);
	if (len_a == 2)
	{
		swap_op(*a);
		*cmds = add_back_stack(M_SA, *cmds);
	}
	else if (len_a == 3)
		sort_three(a, cmds, 0);
	else
		sort_greater(a, b, cmds, len_a);
	leave_solve(*a, *cmds);
}
