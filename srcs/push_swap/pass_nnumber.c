/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_nnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:08:29 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/28 20:40:11 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	steps_to_lower(t_stack *a, int max)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(max >= tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(max >= tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

void	pass_nmin(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
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

static int	steps_to_greater(t_stack *a, int min)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(min <= tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(min <= tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

void	pass_nmax(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	int	min;
	int	steps;

	min = get_nmax(*a, chunk_len);
	while (chunk_len--)
	{
		steps = steps_to_greater(*a, min);
		while (steps >= 0 && min > (*a)->n)
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		while (steps < 0 && min > (*a)->n)
		{
			reverse_rotate_op(a);
			*cmds = add_back_stack(M_RRA, *cmds);
		}
		push_op(b, a);
		*cmds = add_back_stack(M_PB, *cmds);
	}
}
