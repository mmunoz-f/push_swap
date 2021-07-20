/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:39:17 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/20 23:46:42 by mmunoz-f         ###   ########.fr       */
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
	while (n--)
	{
		if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
		if (steps_to_min(*a, mid) >= 0)
		{
			while (mid < (*a)->n)
			{
				rotate_op(a);
				*cmds = add_back_stack(M_RA, *cmds);
			}
		}
		else
		{
			while (mid < (*a)->n)
			{
				reverse_rotate_op(a);
				*cmds = add_back_stack(M_RRA, *cmds);
			}
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
	if (len > 3)
		len = stack_len(*a) % 3;
	else
		len = 0;
	if (len)
		mid_value = get_mid_value(*a, len);
	pass_nnumber_belowx(a, b, cmds, len, mid_value);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds, int len_a)
{
	(void)len_a;
	send_sixths(a, b, cmds);
	while (1)
	{
		if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
		while (*cmds)
			print_cmds(cmds);
		solve_six(a, cmds);
		solve_six(b, cmds);
	}
}
