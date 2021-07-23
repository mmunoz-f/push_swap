/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:33:05 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/23 00:34:12 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

static int	steps_to_min(t_stack *a, int mid_value)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && mid_value < tmp1->n)
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && mid_value < tmp2->n)
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

void	pass_half(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	steps;
	int	mid;
	int	len;

	len = stack_len(*a);
	len /= 2;
	mid = get_mid_value(*a, len);
	while (len--)
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
