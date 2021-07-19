/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:41:00 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/19 20:38:41 by mmunoz-f         ###   ########.fr       */
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
	len /= 2;
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

static void	half_pass(t_stack **a, t_stack **b, int	mid_value, int len_a)
{
	while (len_a)
	{
		if (steps_to_min(*a, mid_value) <= 0)
		{
			while (mid_value < (*a)->n)
			{
				rotate_op(a);
				write(STDOUT_FILENO, "ra\n", 3);
			}
		}
		else
		{
			while (mid_value < (*a)->n)
			{
				reverse_rotate_op(a);
				write(STDOUT_FILENO, "rra\n", 4);
			}
		}
		push_op(b, a);
		write(STDOUT_FILENO, "pb\n", 3);
		len_a--;
		read_stack(*a, "Stack a");
		read_stack(*b, "Stack b");
	}
}

static void	prepare_halfs(t_stack **a, t_stack **b, int len_a)
{
	int	mid_value;

	read_stack(*a, "Stack a");
	read_stack(*b, "Stack b");
	while (len_a > 3)
	{
		if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
		{
			merge_stack(*a, *b);
			leave_solve(*a);
		}
		mid_value = get_mid_value(*a, len_a);
		printf("Mid_value: %i\n", mid_value); //
		half_pass(a, b, mid_value, len_a / 2);
		len_a = stack_len(*a);
		read_stack(*a, "Stack a");
		read_stack(*b, "Stack b");
		printf("\nNEXT SUBDIVISION\n");	//
	}
}

void	sort_greater(t_stack **a, t_stack **b, int len_a)
{
	prepare_halfs(a, b, len_a);
	if (!is_ordered(*a, 1) && !is_ordered(*b, 0))
	{
		merge_stack(*a, *b);
		leave_solve(*a);
	}
}
