/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:40:27 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/05/27 17:40:27 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_stack *a)
{
	int		c;
	t_stack	*b;

	if (!a || !(a->next))
		return ;
	b = a->next;
	c = b->n;
	b->n = a->n;
	a->n = c;
}

void	push_op(t_stack **a, t_stack **b)
{
	if (!(*b))
		return ;
	*a = add_front_stack((*b)->n, *a);
	*b = remove_front_stack(*b);
}

void	rotate_op(t_stack **a)
{
	int	first;

	if (!(*a))
		return ;
	first = (*a)->n;
	*a = remove_front_stack(*a);
	*a = add_back_stack(first, *a);
}

void	reverse_rotate_op(t_stack **a)
{
	int		last;
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->n;
	*a = add_front_stack(last, *a);
	*a = remove_back_stack(*a);
}
