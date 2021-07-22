/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:39:17 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/22 20:52:57 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max_min(t_stack *a, int *max, int *min)
{
	*max = a->n;
	*min = a->n;
	while (a)
	{
		if (*max < a->n)
			*max = a->n;
		if (*min > a->n)
			*min = a->n;
		a = a->next;
	}
}

int	get_mid_value(t_stack *a, unsigned int len)
{
	t_stack	*tmp;
	int		max;
	int		min;
	int		next_min;

	get_max_min(a, &max, &min);
	while (--len)
	{
		tmp = a;
		next_min = max;
		while (tmp)
		{
			if (next_min > tmp->n && tmp->n > min)
				next_min = tmp->n;
			tmp = tmp->next;
		}
		min = next_min;
	}
	return (min);
}

static void	pass_nnumber_belowx(t_stack **a, t_stack **b, t_stack **cmds, int n)
{
	int	steps;
	int	mid;

	if (n < 6)
	{
		n = 3;
		mid = get_mid_value(*a, 3);
	}
	else
		mid = get_mid_value(*a, 6);
	while (n--)
	{
		steps = steps_to_min(*a, mid);
		while (mid < (*a)->n && steps >= 0)
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		while (mid < (*a)->n && steps < 0)
		{
			reverse_rotate_op(a);
			*cmds = add_back_stack(M_RRA, *cmds);
		}
		push_op(b, a);
		*cmds = add_back_stack(M_PB, *cmds);
	}
}

static void	send_sixths(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	len;

	len = stack_len(*a);
	while (len > 6)
	{
		pass_nnumber_belowx(a, b, cmds, 6);
		len = stack_len(*a);
	}
	if (len > 3)
		pass_nnumber_belowx(a, b, cmds, len % 3);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	i;
	int	len;

	send_sixths(a, b, cmds);
	// read_stack(*a, "INIT a\n");
	// read_stack(*b, "INIT b\n");
	while (1)
	{
		len = stack_len(*b);
		if (*b && len >= 6 && !(len % 6))
			pass_three_biggest(a, b, cmds);
		// read_stack(*a, "after pass a\n");
		// read_stack(*b, "AFter pass b\n");
		while (*cmds)
			print_cmds(cmds);
		if (!is_ordered(*a, 1) && !*b)
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
		// read_stack(*a, "Pre solve six a\n");
		// read_stack(*b, "Pre solve six b\n");
		solve_six(a, cmds);
		solve_six(b, cmds);
		// read_stack(*a, "Post solve six a\n");
		// read_stack(*b, "Post solve six b\n");
		i = 3;
		while (i--)
		{
			push_op(a, b);
			*cmds = add_back_stack(M_PA, *cmds);
		}
	}
}
