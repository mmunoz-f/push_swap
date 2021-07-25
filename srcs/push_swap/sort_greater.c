/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:27:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/25 02:22:44 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static unsigned int	get_chunks_lenth(t_stack **a)
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
	return (chunk_lenth);
}

static int	steps_to_num(t_stack *a, int min, int max)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(min < tmp1->n && max > tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(min < tmp2->n && max > tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

static void	pass_chunk(t_stack **a, t_stack **b, t_stack **cmds, int limits[3])
{
	int	steps;

	while (limits[2]--)
	{
		steps = steps_to_num(*a, limits[0], limits[1]);
		while (!(limits[0] < (*a)->n && limits[1] > (*a)->n) && steps >= 0)
		{
			rotate_op(a);
			*cmds = add_back_stack(M_RA, *cmds);
		}
		while (!(limits[0] < (*a)->n && limits[1] > (*a)->n) && steps < 0)
		{
			reverse_rotate_op(a);
			*cmds = add_back_stack(M_RRA, *cmds);
		}
		push_op(b, a);
		*cmds = add_back_stack(M_PB, *cmds);
	}
}

static void	split_in_chunks(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_lenth)
{
	int		i;
	int		chunk_limits[3];
	t_stack	*tmp;

	tmp = cpy_stack(*a, stack_len(*a));
	while (tmp)
	{
		get_max_min(tmp, &chunk_limits[1], 0);
		chunk_limits[0] = get_mid_value(tmp, stack_len(tmp) - chunk_lenth + 1);
		i = chunk_lenth;
		while (i)
		{
			if (tmp->n >= chunk_limits[0])
			{
				tmp = remove_front_stack(tmp);
				i--;
			}
			else
				rotate_op(&tmp);
		}
		chunk_limits[2] = chunk_lenth / 2 + 1;
		pass_chunk(a, b, cmds, chunk_limits);
	}
	while (*a)
		pass_half(a, b, cmds, chunk_lenth / 2);
	free_stack(tmp);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	t_stack			*b_cmds;
	unsigned int	chunk_lenth;

	b_cmds = 0;
	chunk_lenth = get_chunks_lenth(a);
	split_in_chunks(a, b, cmds, chunk_lenth);
	merge_stack(a, b, cmds);
	while (*cmds)
		print_cmds(cmds);
}
