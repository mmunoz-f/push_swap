/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:12:59 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/26 17:28:17 by mmunoz-f         ###   ########.fr       */
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

static int	steps_to_lower(t_stack *a, int max)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(max < tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(max < tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

static void	pass_nmin(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	int	max;
	int	steps;

	max = get_nmin(*a, chunk_len);
	while (chunk_len--)
	{
		steps = steps_to_lower(*a, max);
		while (steps >= 0 && max < (*a)->n)
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		while (steps < 0 && max < (*a)->n)
		{
			reverse_rotate_op(a);
			*cmds = add_back_stack(M_RRA, *cmds);
		}
		push_op(b, a);
		*cmds = add_back_stack(M_PB, *cmds);
	}
}

void	sort_up_to_six(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack	*b_cmds;

	pass_nmin(a, b, cmds, 3);
	while (*cmds)
		print_cmds(cmds);
	b_cmds = 0;
	sort_reverse_three(b, &b_cmds, 1);
	sort_three(a, cmds, 0);
	compare_cmds(cmds, &b_cmds);
	while (*b)
	{
		push_op(a, b);
		*cmds = add_back_stack(M_PA, *cmds);
	}
	while (*cmds)
		print_cmds(cmds);
}
