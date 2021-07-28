/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:55:05 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/28 20:41:23 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	steps_to_num(t_stack *a, int min, int max)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(min <= tmp1->n && max >= tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(min <= tmp2->n && max >= tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

static void	pass_nbetween(t_stack **a, t_stack **b, t_stack **cmds, int limits[3])
{
	int	steps;

	while (limits[2]--)
	{
		steps = steps_to_num(*a, limits[0], limits[1]);
		while (!(limits[0] <= (*a)->n && limits[1] >= (*a)->n) && steps >= 0)
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		while (!(limits[0] <= (*a)->n && limits[1] >= (*a)->n) && steps < 0)
		{
			reverse_rotate_op(a);
			*cmds = add_back_stack(M_RRA, *cmds);
		}
		push_op(b, a);
		*cmds = add_back_stack(M_PB, *cmds);
	}
}

static void	pass_second_half(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	unsigned int	len;

	while (*a)
	{
		len = stack_len(*a);
		if (len > chunk_len)
			len = chunk_len;
		pass_nmin(a, b, cmds, len);
	}
}

void	pass_chunks(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	t_stack *tmp[3];
	int		limits[3];

	tmp[0] = cpy_stack(*a, stack_len(*a));
	tmp[1] = 0;
	tmp[2] = 0;
	while (stack_len(tmp[0]) >= chunk_len)
	{
		limits[1] = get_nmax(tmp[0], 1);
		limits[0] = get_nmin(tmp[0], stack_len(tmp[0]) - chunk_len + 1);
		if (chunk_len % 2)
			limits[2] = chunk_len / 2 + 1;
		else
			limits[2] = chunk_len / 2;
		pass_nmax(&tmp[0], &tmp[1], &tmp[2], chunk_len);
		pass_nbetween(a, b, cmds, limits);
	}
	free_stack(tmp[0]);
	free_stack(tmp[1]);
	free_stack(tmp[2]);
	pass_second_half(a, b, cmds, chunk_len / 2);
}
