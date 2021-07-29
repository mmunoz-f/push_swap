/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:33:05 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/29 19:47:13 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_stack *a)
{
	int	max;

	max = a->n;
	while (a)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}

static int	get_min(t_stack *a)
{
	int	min;

	min = a->n;
	while (a)
	{
		if (min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

int	get_nmax(t_stack *a, unsigned int n)
{
	t_stack	*tmp;
	int		max;
	int		next_max;

	max = get_max(a);
	while (--n)
	{
		tmp = a;
		next_max = get_min(a);
		while (tmp)
		{
			if (tmp->n > next_max && tmp->n < max)
				next_max = tmp->n;
			tmp = tmp->next;
		}
		max = next_max;
	}
	return (max);
}

int	get_nmin(t_stack *a, unsigned int n)
{
	t_stack	*tmp;
	int		min;
	int		next_min;

	min = get_min(a);
	while (--n)
	{
		tmp = a;
		next_min = get_max(a);
		while (tmp)
		{
			if (tmp->n < next_min && tmp->n > min)
				next_min = tmp->n;
			tmp = tmp->next;
		}
		min = next_min;
	}
	return (min);
}
