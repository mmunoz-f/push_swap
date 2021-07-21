/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:39:17 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 22:00:31 by mmunoz-f         ###   ########.fr       */
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

static void	pass_nnumber_belowx(t_stack **a, t_stack **b, t_stack **cmds, int n)
{
	int	steps;
	int	mid;

	if (n <= 6)
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
		pass_nnumber_belowx(a, b, cmds, len);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	i;

	send_sixths(a, b, cmds);
	while (1)
	{
		while (*cmds)
			print_cmds(cmds);
		read_stack(*a,"IStack a\n");
		read_stack(*b,"IStack b\n");
		if (!is_ordered(*a, 1) && !*b)
		{
			merge_stack(*a, *b);
			leave_solve(*a, *cmds);
		}
		solve_six(a, cmds);
		solve_six(b, cmds);
		read_stack(*a,"MStack a\n");
		read_stack(*b,"MStack b\n");
		i = 3;
		while (i-- && *b)
		{
			push_op(a, b);
			*cmds = add_back_stack(M_PA, *cmds);
		}
		pass_three_biggest(a, b, cmds);
		read_stack(*a,"FStack a\n");
		read_stack(*b,"FStack b\n");
	}
}
