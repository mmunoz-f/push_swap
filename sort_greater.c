/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:39:17 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 18:43:34 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_max_min(t_stack *a, int *max, int *min)
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

static int	get_mid_value(t_stack *a, unsigned int len)
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

static void	pass_nnumber_belowx(t_stack **a, t_stack **b, t_stack **cmds, int n, int mid)
{
	int	steps;

	while (n--)
	{
		if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
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
	int	mid_value;
	int	len;

	len = stack_len(*a);
	mid_value = get_mid_value(*a, 6);
	while (stack_len(*a) > 6)
	{
		pass_nnumber_belowx(a, b, cmds, 6, mid_value);
		len = stack_len(*a);
		mid_value = get_mid_value(*a, 6);
	}
	if (len == 6)
		pass_nnumber_belowx(a, b, cmds, 3, mid_value);
	else if (len > 3)
		len = stack_len(*a) % 3;
	else
		len = 0;
	if (len)
		mid_value = get_mid_value(*a, len);
	pass_nnumber_belowx(a, b, cmds, len, mid_value);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	i;

	send_sixths(a, b, cmds);
	while (1)
	{
		while (*cmds)
			print_cmds(cmds);
		if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
		solve_six(a, cmds);
		solve_six(b, cmds);
		i = 3;
		while (i-- && *b)
		{
			push_op(a, b);
			*cmds = add_back_stack(M_PA, *cmds);
		}
	}
}
