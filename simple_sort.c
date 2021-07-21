/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:00:51 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 22:10:13 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_the_three(t_stack *b, int *n1, int *n2, int *n3)
{
	int	min;
	int	max;

	get_max_min(b, &max, &min);
	*n1 = min;
	*n2 = min;
	*n3 = min;
	while (b)
	{
		if (b->n > *n1)
			*n1 = b->n;
		else if (b->n > *n2)
			*n2 = b->n;
		else if (b->n > *n3)
			*n3 = b->n;
		b = b->next;
	}
}

void	pass_three_biggest(t_stack **a, t_stack **b, t_stack **cmds)
{
	int	n[3];
	int	i;

	get_the_three(*b, &n[0], &n[1], &n[2]);
	i = 3;
	while (i)
	{
		if ((*b)->n == n[0] || (*b)->n == n[1] || (*b)->n == n[2])
		{
			push_op(a, b);
			*cmds = add_back_stack(M_PA, *cmds);
			i--;
		}
		*b = (*b)->next;
	}
}

void	simple_solve(t_stack **a, t_stack **cmds)
{
	t_stack	*tmp;

	tmp = cpy_stack(*a, 3);
	while (is_ordered(*a, 1))
	{
		if ((*a)->n > (*a)->next->n)
		{
			swap_op(*a);
			swap_op(tmp);
			*cmds = add_back_stack(M_SA, *cmds);
		}
		else
		{
			rotate_op(a);
			rotate_op(&tmp);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		reverse_rotate_op(a);
		reverse_rotate_op(&tmp);
		*cmds = add_back_stack(M_RRA, *cmds);
	}
}

void	simple_reverse_solve(t_stack **b, t_stack **cmds)
{
	t_stack	*tmp;

	tmp = cpy_stack(*b, 3);
	while (is_ordered(tmp, 0))
	{
		if ((*b)->n < (*b)->next->n)
		{
			swap_op(*b);
			swap_op(tmp);
			*cmds = add_back_stack(M_SB, *cmds);
		}
		else
		{
			rotate_op(b);
			rotate_op(&tmp);
			*cmds = add_back_stack(M_RB, *cmds);
		}
		reverse_rotate_op(b);
		reverse_rotate_op(&tmp);
		*cmds = add_back_stack(M_RRB, *cmds);
	}
}
