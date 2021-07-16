/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_great_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:12:27 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/16 02:53:49 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_min(t_stack *a, int mid_value)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		steps;

	tmp1 = cpy_stack(a);
	tmp2 = cpy_stack(a);
	steps = 0;
	while (tmp1 && mid_value > tmp1->n)
	{
		rotate_op(&tmp1);
		steps--;
	}
	while (tmp2 && mid_value > tmp2->n)
	{
		reverse_rotate_op(&tmp2);
		steps++;
	}
	free_stack(tmp1);
	free_stack(tmp2);
	return (steps);
}
