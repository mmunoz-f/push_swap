/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:33:05 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/24 18:34:56 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	get_max_min(t_stack *a, int *max, int *min)
{
	if (max)
		*max = a->n;
	if (min)
		*min = a->n;
	while (a)
	{
		if (max && *max < a->n)
			*max = a->n;
		if (min && *min > a->n)
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

void	pass_half(t_stack **a, t_stack **b, t_stack **cmds, unsigned int len)
{
	int	steps;
	int	mid;

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

unsigned int	divide_in_chunks(t_stack **a, t_stack **b, t_stack **cmds)
{
	unsigned int	len;
	unsigned int	chunk_lenth;

	len = stack_len(*a);
	if (len <= 20)
		chunk_lenth = 5;
	else if (len < 100)
		chunk_lenth = 10;
	else if (len < 500)
		chunk_lenth = 20;
	else
		chunk_lenth = 50;

	while (stack_len(*a) > chunk_lenth)
		pass_half(a, b, cmds, chunk_lenth);
	return (chunk_lenth);
}
