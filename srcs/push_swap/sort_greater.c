/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:27:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/25 06:24:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static unsigned int	number_of_chunks(t_stack *a)
{
	unsigned int	len;
	unsigned int	chunks;

	len = stack_len(a);
	if (len <= 20)
		chunks = 2;
	else if (len < 100)
		chunks = 5;
	else if (len < 500)
		chunks = 8;
	else
		chunks = 11;
	return (chunks);
}

static int	steps_to_greater(t_stack *a, int min)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a, stack_len(a));
	tmp2 = cpy_stack(a, stack_len(a));
	steps = 0;
	while (tmp1 && !(min < tmp1->n))
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && !(min < tmp2->n))
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}

static void	pass_nmax(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
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

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	unsigned int	chunk_len;

	chunk_len = stack_len(*a) / number_of_chunks(*a);
	while (stack_len(*a) > chunk_len)
		pass_nmax(a, b, cmds, chunk_len);
	read_stack(*a, "Init stack a\n");
	read_stack(*b, "Init stack b\n");
}
