/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:27:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/24 19:00:46 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// static void	sort_reverse_chunks(t_stack **b, t_stack **cmds, unsigned int chunk_lenth)
// {
// 	t_stack *a;
// 	t_stack	*tmp;
// 	t_stack	*sorted;
// 	int		max;

// 	sorted = 0;
// 	a = 0;
// 	tmp = cpy_stack(*b, chunk_lenth);
// 	while (is_ordered(sorted, 0) || tmp)
// 	{
// 		get_max_min(tmp, &max, 0);
// 		if (tmp->n == max)
// 		{
// 			push_op(&sorted, &tmp);
// 			rotate_op(b);
// 			*cmds = add_back_stack(M_RB, *cmds);
// 		}
// 		else if (tmp->n < tmp->next->n)
// 		{
// 			swap_op(tmp);
// 			swap_op(*b);
// 			*cmds = add_back_stack(M_SB, *cmds);
// 		}
// 	}
// }

// static void	sort_chunks(t_stack **a, t_stack **cmds, unsigned int chunk_lenth)
// {
// 	t_stack	*b;
// 	t_stack	*tmp;
// 	t_stack	*sorted;
// 	int		min;

// 	sorted = 0;
// 	b = 0;
// 	tmp = cpy_stack(*a, chunk_lenth);
// 	while (is_ordered(sorted, 1) || tmp)
// 	{
// 		get_max_min(tmp, 0, &min);
// 		if (tmp->n == min)
// 		{
// 			push_op(&sorted, &tmp);
// 			rotate_op(a);
// 			*cmds = add_back_stack(M_RA, *cmds);
// 		}
// 		else if (tmp->n > tmp->next->n)
// 		{
// 			swap_op(tmp);
// 			swap_op(*a);
// 			*cmds = add_back_stack(M_SA, *cmds);
// 		}
// 	}
// }

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack			*b_cmds;
	unsigned int	chunk_lenth;
	// unsigned int	i;

	b_cmds = 0;
	chunk_lenth = divide_in_chunks(a, b, cmds);
	while (*cmds)
		print_cmds(cmds);
	// read_stack(*a, "stack a\n");
	// read_stack(*b, "stack b\n");
	// while (*b)
	// {
	// 	simple_solve(a, cmds, chunk_lenth);
	// 	simple_reverse_solve(b, &b_cmds, chunk_lenth);
	// 	compare_cmds(cmds, &b_cmds);
	// 	i = chunk_lenth * 2;
	// 	while (i--)
	// 	{
	// 		push_op(a, b);
	// 		*cmds = add_back_stack(M_PA, *cmds);
	// 	}
	// 	while (*cmds)
	// 		print_cmds(cmds);
	// }
}
